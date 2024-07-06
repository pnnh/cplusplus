#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    // 输出文件流示例
    ofstream file { "lunchtime.txt", ios::out | ios::app};
    file << "Time is an illusion. Lunchtime doubly so.\n";
    file << "Lunch time, " << 2 << "x so" << endl;

    // 输入文件流示例
    // 运行之前先在当前工作目录下创建numbers.txt的文件，每行是一个数字
    std::string path{"numbers.txt"};
    ifstream numbersFile {path};
    if (!numbersFile.is_open())
    {
        string err{"Unable to open file"};
        err.append(path);
        throw runtime_error{err};
    }
    numbersFile.exceptions(ifstream::badbit);
    auto maximum = numeric_limits<int>::min();
    int value;
    while (numbersFile >> value)
        maximum = maximum < value ? value : maximum;
    cout << "Maximum found was " << maximum << endl;
}