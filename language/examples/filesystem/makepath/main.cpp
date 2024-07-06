#include <iostream>
#include <filesystem>

using namespace std;

int main() {
    try {
        const auto temp_path = filesystem::temp_directory_path();
        const auto relative = filesystem::relative(temp_path);
        cout << boolalpha
        << "Temporary directory path: " << temp_path
        <<"\nTemporary directory absolute path" << temp_path.is_absolute()
        << "\nCurrent path: "<<filesystem::current_path()
        << "\nTemporary directory's relative path: " << relative
        << "\nRelative directory absolute: " << relative.is_absolute()
        << "\nChanging current direcotyr to temp.";
        filesystem::current_path(temp_path);
        cout <<"\nCurrent path after change: " << filesystem::current_path();
    } catch(const exception& e) {
        cerr << "Error: " << e.what();
    }
    return 0;
}