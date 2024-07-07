#include <iostream>
#include <string>
#include <type_traits>
#include <cstddef>

using namespace std;

template<typename T, typename U>
concept is_same_as = std::is_same_v<T, U>;

template<typename T>
concept Averageable = std::is_default_constructible<T>::value && requires(T a, T b) {
    { a + b } -> is_same_as<typename std::decay<decltype(a)>::type>;
    { a / size_t{1}} -> is_same_as<typename std::decay<T>::type>;
};

template<Averageable T>
T mean(T *a, size_t length) {
    typename std::decay<T>::type result{};
    for (size_t i{}; i < length; i++) {
        result += a[i];
    }
    return result / length;
}

int main() {

    const double nums_d[]{1.0f, 2.0f, 3.0f, 4.0f};
    const auto result1 = mean(nums_d, 4);
    printf("double: %f\n", result1);

    float nums_f[]{1.0f, 2.0f, 3.0f, 4.0f};
    auto result2 = mean(nums_f, 4);
    printf("float: %f\n", result2);

    size_t nums_c[]{1, 2, 3, 4};
    const auto result3 = mean(nums_c, 4);
    printf("size_t: %zu\n", result3);

    return 0;
}