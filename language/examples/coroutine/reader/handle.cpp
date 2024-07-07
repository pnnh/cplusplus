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
            static int seed = 0;
            value = ++seed;
            std::cout << "thread: " << value << std::endl;

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
        Task get_return_object() {
            return Task{
                    std::coroutine_handle<promise_type>::from_promise(*this)
            };
        }

        std::suspend_always yield_value(int v) {
            value = v;
            return {};
        }

        void return_void() {

        }

        std::suspend_never initial_suspend() {
            return {};
        }

        std::suspend_never final_suspend() noexcept {
            return {};
        }

        void unhandled_exception() {

        }

        int GetValue() const {
            return value;
        }

    private:
        int value;
    };

    Task(std::coroutine_handle<promise_type> handle) : coroutine_handle(handle) {

    }

    int GetValue() {
        return coroutine_handle.promise().GetValue();
    }

    void Next() {
        coroutine_handle.resume();
    }

private:
    std::coroutine_handle<promise_type> coroutine_handle;
};

Task GetInt() {
    while (true) {
        IntReader reader;
        int value = co_await reader;
        co_yield value;
    }
}

int main() {
    auto task = GetInt();

    std::string line;
    // 输入任意字符并回车以查看下一个值
    while (std::cin >> line) {
        std::cout << "Value: " << task.GetValue() << std::endl;
        task.Next();
    }

    return 0;
}