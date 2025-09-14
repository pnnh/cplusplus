---
cls: MTNote
uid: 0199486a-81eb-7150-8e99-bd6db5915a0f
title: 演示标准C++ adjacent_find算法
---

adjacent_find是一个算法函数，定义在<algorithm>头文件中。它用于在容器或范围中查找满足特定条件的相邻元素，并返回指向第一个满足条件的元素的迭代器。如果没有找到这样的相邻元素，则返回范围的末尾迭代器。

本示例演示从一个字符串数组中查找相邻的，首字母相同的两个元素。

### 构建执行

```bash
mkdir cmake-build && cd cmake-build
cmake ..
make
# 执行
./algorithm_adjacent_find
```
