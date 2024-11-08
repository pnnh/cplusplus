#include <iostream>
#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp>

void Print1() {
  for (int i = 0; i < 5; i++) {
    boost::this_thread::sleep_for(boost::chrono::milliseconds{500});
    std::cout << "[Print1] Line: " << i << '\n';
  }
}

void Print2() {
  for (int i = 0; i< 5; i++) {
    boost::this_thread::sleep_for(boost::chrono::milliseconds{500});
    std::cout << "[Print2] Line: " << i << '\n';
  }
}

int main(int argc, char *argv[]) {
  boost::thread_group threads;
  threads.create_thread(Print1);
  threads.create_thread(Print2);
  threads.join_all();
}