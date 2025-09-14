#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 查找序列中第一对相邻重复元素，满足指定条件
    vector<string> words{"Icabod", "is", "itchy", "italiy", "wat", "in", "Iowa"};
    const auto first_leters_match = [](const auto &word1, const auto &word2) {
        if (word1.empty() || word2.empty()) return false;
        return word1.front() == word2.front();
    };
    const auto adjcent_find_result = adjacent_find(words.cbegin(), words.cend(), first_leters_match);
    if (adjcent_find_result != words.cend()) {
        cout << "Found adjacent words with the same first letter: " << *adjcent_find_result << " and "
             << *(adjcent_find_result + 1) << endl;
    } else {
        cout << "No adjacent words with the same first letter found\n";
    }

    return 0;
}