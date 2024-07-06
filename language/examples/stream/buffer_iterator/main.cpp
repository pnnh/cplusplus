#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    ostreambuf_iterator<char> itr {cout};
    *itr = 'H';
    ++itr;
    *itr = 'i';

    // 测试输入缓冲区迭代器
    // 从输入流中读取字符，直到遇到EOF（Clion macOS下输入回车然后按Command+D）
    istreambuf_iterator<char> cin_itr{cin.rdbuf()}, end{};
    cout << "\nWhat is your name? ";
    const string name {cin_itr, end};
    cout << "Hello, " << name << "!\n";
}