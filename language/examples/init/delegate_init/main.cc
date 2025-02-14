#include <vector>
#include <list>
#include <deque>

class X {
  template<class T>
  X(T first, T last) : l_(first, last) {}

  std::list<int> l_;

 public:
  X(std::vector<short> &);
  X(std::deque<int> &);
};

X::X(std::vector<short> &v) : X(v.begin(), v.end()) {}
X::X(std::deque<int> &v) : X(v.begin(), v.end()) {}

int main(int argc, char *argv[]) {
  std::vector<short> a{1, 2, 3, 4, 5};
  std::deque<int> b{1, 2, 3, 4, 5};
  X x1(a);
  X x2(b);
}