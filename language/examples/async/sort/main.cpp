#include <string>
#include <future>
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <numbers>
#include <execution>
#include <random>

using namespace std;
using namespace literals::chrono_literals;


struct Stopwatch {
    chrono::nanoseconds elapsed_ns;

    explicit Stopwatch(chrono::nanoseconds &elapsed_ns) : elapsed_ns{elapsed_ns} {
        elapsed_ns = chrono::high_resolution_clock::now().time_since_epoch();
    }

    ~Stopwatch() {
        elapsed_ns = chrono::high_resolution_clock::now().time_since_epoch() - elapsed_ns;
    }
};

vector<long> make_random_vector() {
    vector<long> numbers(1'000'000'000);
    iota(numbers.begin(), numbers.end(), 0);
    mt19937_64 urng{121216};
    shuffle(numbers.begin(), numbers.end(), urng);
    return numbers;
}

int main() {
    cout << "Constructing random vector...\n";
    auto numbers_a = make_random_vector();
    auto numbers_b = make_random_vector();
    chrono::nanoseconds time_to_sort;
    cout << " " << numbers_a.size() << " elements.\n";
    cout << "Sorting with execution::seq...\n";
    {
        Stopwatch stopwatch{time_to_sort};
        sort(execution::seq, numbers_a.begin(), numbers_a.end());
    }
    cout << " took " << time_to_sort.count() / 1.0E9 << " seconds.\n";

    cout << "Sorting with execution::par...\n";
    {
        Stopwatch stopwatch{time_to_sort};
        sort(execution::par, numbers_b.begin(), numbers_b.end());
    }
    cout << " took " << time_to_sort.count() / 1.0E9 << " seconds.\n";
    return 0;
}