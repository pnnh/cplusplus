#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Gotham needs its " << boolalpha << true << " hello.";
    cout << "\nMark it " << noboolalpha << false << "!";
    cout << "\nThere are " << hex << 3669732608 << "!";
    cout << "\nAvogadro's number: " << scientific << 6.0221409e23 << "!";
    cout << "\nthe Hogwarts platform: " << fixed << setprecision(2) << 9.750123;
    cout << "\nAlways eliminate " << 373592054;
    cout <<  setw(4) << "\n"
            << "the " << oct << 0xdeadbeef << "!"
    << 0x1 << "\n" << 0x10 << "\n" << 0x100 << "\n" << 0x1000 << endl;
}