#include <iostream>

namespace Parent {
    namespace Child1 {
        void foo() {
            std::cout << "Child1::foo()" << std::endl;
        }
    }
    inline namespace Child2 {
        void foo() {
            std::cout << "Child2::foo()" << std::endl;
        }
    }
}

namespace A::inline B::C {
    void foo() {
        std::cout << "A::B::C::foo()" << std::endl;
    }
}

int main() {
    Parent::foo();
    Parent::Child1::foo();
    A::C::foo();
    A::B::C::foo();
    return 0;
}