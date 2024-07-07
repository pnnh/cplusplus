#include <initializer_list>
#include <type_traits>

template<class T>
auto return_ref1(T &t) {
    return t;
}
// decltype(return_ref1(x1)) -> int

template<class T>
auto return_ref2(T &t) -> decltype(t) {
    return t;
}
// decltype(return_ref2(x1)) -> int&

template<class T>
decltype(auto) return_ref3(T &t) {
    return t;
}
// decltype(return_ref3(x1)) -> int&

int main() {
    const int &&foo();
    int i;
    struct A {
        double x;
    };
    const A *a = new A();

    decltype(foo());    // const int&&
    decltype(i);        // int
    decltype(a->x);     // double
    decltype((a->x));   // const double&

    auto t = &(a->x);   // const double*

    int *j;
    int n[10];
    const int &&foo();
    decltype(static_cast<short>(i));    // short

    decltype(j);    // int*
    decltype(n);    // int[10]
    decltype(foo);  // const int&& (*)()
    decltype(foo());    // const int&&

    struct Abstract {
        int operator()() { return 10; }
    };
    Abstract abstract;
    decltype(abstract());    // int

    decltype(i = 0);  // int&
    decltype(0, i); // int&
    decltype(i, 0); // int
    decltype(n[5]);    // int&
    decltype(*j);  // int&
    decltype(static_cast<int &&>(i));    // int&&
    decltype(i++);  // int
    decltype(++i);  // int&
    decltype("hello world");    // const char(&)[12]


    int &&f();
    auto x1a = i;   // int
    decltype(auto) x1d = i; // int
    auto x2a = (i); // int
    decltype(auto) x2d = (i);   // int&
    auto x3a = f(); // int
    decltype(auto) x3d = f();   // int&&
    auto x4a = {1, 2};  // std::initializer_list<int>
    // decltype(auto) x4d = {1, 2};    // 将会编译失败，因为{1,2}不是表达式
    auto *x5a = &i; // int*
    // decltype(auto) *x5d = &i;   // 编译失败，decltype(auto)必须单独声明


    int x1 = 0;
    // static_assert(std::is_reference_v<decltype(return_ref1(x1))>);  // 编译失败，结果为false
    static_assert(std::is_reference_v<decltype(return_ref2(x1))>);  // 编译成功，结果为true
    static_assert(std::is_reference_v<decltype(return_ref3(x1))>);   // 编译成功，结果为true


    return 0;
}