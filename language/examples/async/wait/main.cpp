#include <string>
#include <future>
#include <iostream>

using namespace std;
using namespace literals::chrono_literals;

int main() {
    auto sleepy = async(launch::async, [] {
        this_thread::sleep_for(100ms);
    });
    const auto not_ready_yet = sleepy.wait_for(25ms);
    if (not_ready_yet == future_status::timeout) {
        cout << "Not ready yet\n";
    }
    const auto totally_ready = sleepy.wait_for(100ms);
    if (totally_ready == future_status::ready) {
        cout << "Totally ready\n";
    }
    return 0;
}