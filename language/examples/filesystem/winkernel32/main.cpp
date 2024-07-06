#include <iostream>
#include <filesystem>

using namespace std;

int main() {
    const filesystem::path kernel32 {R"(C:\Windows\System32\kernel32.dll)"};
    cout <<"Root name: " << kernel32.root_name()
    << "\nRoot directory: " << kernel32.root_directory()
    << "\nRelative path: " << kernel32.root_path()
    <<"\nParent path: " << kernel32.parent_path()
    << "\nFilename: " << kernel32.filename()
    <<"\nStem: " << kernel32.stem()
    << "\nExtension: " << kernel32.extension()
    << endl;
    return 0;
}