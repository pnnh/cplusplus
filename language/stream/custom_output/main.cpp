#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
    os << "Size: " << v.size()
    << "\nCapacity: " << v.capacity()
    << "\nElements:\n";
    for (const auto& element: v)
    {
        os << "\t" << element << "\n";
    }
    return os;
}

int main()
{
    const vector<string> characters {
        "Body Shaftos",
        "Lawrence Waterhouse",
        "Gunter Bischoff",
        "Earl comstock"
    };
    cout << characters << endl;

    const vector<bool> bits {true, false, true, false};
    cout << boolalpha << bits << endl;
}