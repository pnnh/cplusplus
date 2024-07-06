#include <string>
#include <future>
#include <iostream>
#include <set>
#include <sstream>
#include <array>

template<typename T>
std::set<T> factorize(T x) {
    std::set<T> result{1};
    for (T candidate{2}; candidate <= x; candidate++) {
        if (x % candidate == 0) {
            result.insert(candidate);
            x /= candidate;
            candidate = 1;
        }
    }
    return result;
}

using namespace std;

struct Stopwatch {
    chrono::nanoseconds elapsed_ns;

    explicit Stopwatch(chrono::nanoseconds &elapsed_ns) : elapsed_ns{elapsed_ns} {
        elapsed_ns = chrono::high_resolution_clock::now().time_since_epoch();
    }
};

string factor_task(unsigned long x) {
    chrono::nanoseconds elapsed_ns;
    set<unsigned long> factors;
    {
        Stopwatch stopwatch{elapsed_ns};
        factors = factorize(x);
    }
    const auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(elapsed_ns).count();
    stringstream ss;
    ss << elapsed_ms << " ms Factoring " << x << " ( ";
    for (auto factor: factors) ss << factor << " ";
    ss << ")\n";
    return ss.str();
}

array<unsigned long long, 6> numbers{
        9'699'590,
        179'426'549,
        1'000'000'007,
        4'294'967'291,
        4'294'967'296,
        1'307'674'368'000
};

int main() {
    chrono::nanoseconds elapsed_ns;
    {
        Stopwatch stopwatch{elapsed_ns};
        vector<future<string>> factor_tasks;
        for (auto number: numbers)
            factor_tasks.emplace_back(async(launch::async, factor_task, number));
        for (auto &task: factor_tasks)
            cout << task.get();
    }
    const auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(elapsed_ns).count();
    cout << elapsed_ms << " ms: Total program time\n";
    return 0;
}