#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/algorithm/string/case_conv.hpp>

using namespace std;

int main() {
    vector <string> words1{"farewell", "hello", "farewell", "hello"};
    vector <string> result1;
    auto upper = [](string x) {
        boost::algorithm::to_upper(x);
        return x;
    };
    transform(words1.begin(), words1.end(), back_inserter(result1), upper);
    if (result1 == vector < string > {"FAREWELL", "HELLO", "FAREWELL", "HELLO"}) {
        cout << "Transformed words1 to uppercase successfully\n";
    } else {
        cout << "Failed to transform words1 to uppercase\n";
    }

    vector <string> words2{"light", "human", "bro", "quantum"};
    vector <string> words3{"radar", "robot", "pony", "bit"};
    vector <string> result2;

    auto portmantize = [](const auto &x, const auto &y) {
        const auto x_letters = min(size_t{2}, x.size());
        string result{x.begin(), x.begin() + x_letters};
        const auto y_letters = min(size_t{3}, y.size());
        result.insert(result.end(), y.end() - y_letters, y.end());
        return result;
    };
    transform(words2.begin(), words2.end(), words3.begin(), back_inserter(result2), portmantize);
    if (result2 == vector < string > {"lidar", "hubot", "brony", "qubit"}) {
        cout << "Portmantized words2 and words3 successfully\n";
    } else {
        cout << "Failed to portmantize words2 and words3\n";
    }
    return 0;
}