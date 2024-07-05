#include <iostream>
#include <deque>

using namespace std;

template <typename T>
istream& operator>>(istream& is, deque<T>& t)
{
    T element;
    while (is >> element)
        t.emplace_back(move(element));

    return is;
}

int main()
{
    cout << "Give me numbers: ";
    deque<int> numbers;
    cin >> numbers;
    int sum{};
    cout << "Cumulativve sum: \n";
    for(const auto& element: numbers)
    {
        sum += element;
        cout << sum << "\n";
    }
}