#include <coroutine>
#include <iostream>
#include <thread>
#include <string>
#include <memory>

class IntReader {
public:
    bool await_ready() {
        return false;
    }

    void await_suspend(std::coroutine_handle<> handle) {
        std::thread thread([this, handle] {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            value = std::rand();
            handle.resume();
        });
        thread.detach();
    }

    int await_resume() {
        return value;
    }

private:
    int value{};
};

class Task {
public:
    class promise_type {
    public:
        promise_type() : value(std::make_shared<int>()) {

        }

        Task get_return_object() {
            return Task{value};
        }

        void return_value(int v) {
            *value = v;
        }

        std::suspend_never initial_suspend() {
            return {};
        }

        std::suspend_never final_suspend() noexcept {
            return {};
        }

        void unhandled_exception() {

        }

    private:
        std::shared_ptr<int> value;
    };

    Task(const std::shared_ptr<int> &v) : value(v) {

    }

    int GetValue() {
        return *value;
    }

private:
    std::shared_ptr<int> value;
};

Task GetInt() {
    IntReader reader1;
    int total = co_await reader1;
    std::cout << "First: " << total << std::endl;

    IntReader reader2;
    total += co_await reader2;
    std::cout << "Second: " << total << std::endl;

    IntReader reader3;
    total += co_await reader3;
    // std::cout << "Total: " << total << std::endl;

    co_return total;
}

int main() {
    auto task = GetInt();

    std::string line;
    // 等待用户输入以防止程序退出
    std::getline(std::cin, line);

    // 等待一定时间后用户输入以查看结果
    std::cout << "Total: " << task.GetValue() << std::endl;

    return 0;
}