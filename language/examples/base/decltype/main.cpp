#include <iostream>

struct S1 {
    int x1;
    decltype(x1) x2;
    double x3;
    decltype(x2 + x3) x4;
};

int x1 = 0;

decltype(x1) sum(decltype(x1) a1, decltype(a1) a2) {
    return a1 + a2;
}

auto sum2(int a1, int a2) -> int {
    return a1 + a2;
}

template<class T1, class T2>
auto sum3(T1 a1, T2 a2) -> decltype(a1 + a2) {
    return a1 + a2;
}
// auto x4 = sum3(1, 2.5);

template<class T>
auto return_ref(T &t) -> decltype(t) {
    return t;
}

int main() {
    int x1 = 0;
    double x2 = 5.5;
    std::cout << typeid(x1).name() << std::endl;
    std::cout << typeid(x1 + x2).name() << std::endl;
    std::cout << typeid(int).name() << std::endl;

    auto &t2 = typeid(int); // const std::type_info&
    auto t3 = &typeid(int); // const std::type_info*

    decltype(x1) y1 = 1;
    std::cout << typeid(y1).name() << std::endl;

    double x3 = 5.5;
    decltype(x1 + x3) x4 = x1 + x3;
    std::cout << typeid(x4).name() << std::endl;

    static_assert(std::is_reference_v<decltype(return_ref(x1))>);   // 编译成功，结果为true

    return 0;
}