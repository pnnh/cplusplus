#include <iostream>

template<decltype(auto) N>
void f() {
    std::cout << N << std::endl;
}

static const int x = 11;
static int y = 7;

int main() {
    f<x>();     // N为const int类型
    f<(x)>();   // N为const int&类型
    // f<y>();     // 将会编译错误，因为decltype需要一个表达式，而y不是常量，无法编译期实例化
    f<(y)>();   // N为int&类型
}