---
cls: MTNote
uid: 01994873-fd0d-701c-94d8-1f04064d9ca4
title: 演示标准C++ all_of和any_of算法
---

all_of 和 any_of 算法包含在 \<algorithm\> 头文件中，用于检查容器或范围中的元素是否全部或者部分满足特定条件。它们在功能上互补，适用于需要验证元素属性的场景。

本示例对一个字符串数组应用all_of算法，检查该数组中是否所有字符串都以字母A或a开头，以及是否所有字符串长度都是6个字符。

同时又对该数组应用any_of算法，检查数组中是否存在任意一个字符串，它包含unt子串。

### 代码片段

```c++
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
```

### 构建执行

本实例在Ubuntu 24.04下测试通过。

```bash
mkdir cmake-build && cd cmake-build
cmake ..
make
# 执行
./algorithm_all_of
```
