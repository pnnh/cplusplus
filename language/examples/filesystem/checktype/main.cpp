#include <iostream>
#include <filesystem>

using namespace std;

void describe(const filesystem::path& p){
    cout << boolalpha <<"Path: " << p << endl;
    try {
        cout <<"Is directory: " << filesystem::is_directory(p) << endl;
        cout <<"Is regular file: " << filesystem::is_regular_file(p) << endl;
        cout <<"Is empty: " << filesystem::is_empty(p) << endl;
    } catch (const filesystem::filesystem_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main() {
    filesystem::path win_path{R"(C:/Windows/System32/kernel32.dll)"};
    describe(win_path);
    win_path.remove_filename();
    describe(win_path);


    filesystem::path unix_path{"/usr/bin/bash"};
    describe(unix_path);
    unix_path.remove_filename();
    describe(unix_path);

    return 0;
}