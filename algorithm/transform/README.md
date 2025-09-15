---
cls: MTNote
uid: 01994b39-28ab-7092-9b0c-1e4b46d5fac3
title: 演示标准C++ transform算法
---

transform算法包含在\<algorithm\>头文件中，它用于对一个或多个序列中的元素应用指定的操作，并将结果存储到目标序列中。std::transform常用于数据转换、映射或处理集合中的元素。

本示例演示通过transform算法将一个字符串数组中的每一项都转换成大写，并把结果存到另一个字符串数组中。

同时还演示了同时操作两个字符串数组的用法，两个数组长度要一致。示例里把第一个数组的每一项的前2个字母，和第二个数组中对应项的后3个字母拼接成一个新的字符串，存到目标数组中。

需要注意截取每一项字符串时长度不要越界。

### 代码片段

核心代码片段如下：

```c++
int main() {
    vector <string> words1{"farewell", "hello", "farewell", "hello"};
    vector <string> result1;
    auto upper = [](string x) {
        boost::algorithm::to_upper(x);
        return x;
    };
    std::transform(words1.begin(), words1.end(), back_inserter(result1), upper);
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
```

### 构建执行

本实例在Ubuntu 24.04下测试通过。

```bash
mkdir cmake-build && cd cmake-build
cmake ..
make
# 执行
./algorithm_transform
```
