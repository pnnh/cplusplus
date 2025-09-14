#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<string> words{"Auntie", "Anne's", "alligator"};

    const auto starts_with_a = [](const auto &word) {
        if (word.empty())return false;
        return word[0] == 'A' || word[0] == 'a';
    };
    auto all_start_with_a = all_of(words.begin(), words.end(), starts_with_a);
    const auto has_length_six = [](const auto &word) {
        return word.size() == 6;
    };
    auto all_have_length_six = all_of(words.begin(), words.end(), has_length_six);
    cout << "All words start with 'A': " << boolalpha << all_start_with_a << endl;
    cout << "All words have length 6: " << boolalpha << all_have_length_six << endl;

    const auto contains_unt = [](const auto &word) {
        return word.find("unt") != string::npos;
    };
    auto any_contain_unt = any_of(words.begin(), words.end(), contains_unt);
    cout << "Any words contain 'unt': " << boolalpha << any_contain_unt << endl;

    return 0;
}