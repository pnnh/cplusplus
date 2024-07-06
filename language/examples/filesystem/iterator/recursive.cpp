#include <iostream>
#include <filesystem>
#include <iomanip>

using namespace std;
using namespace std::filesystem;

struct Attributes {
    Attributes& operator+=(const Attributes& other){
        this-> size_bytes += other.size_bytes;
        this -> n_directories += other.n_directories;
        this -> n_files += other.n_files;
        return *this;
    }

    size_t size_bytes;
    size_t n_directories;
    size_t n_files;
};

void print_line(const Attributes& attributes, string_view path){
    cout << setw(14) << attributes.size_bytes
    << setw(14) << attributes.n_directories
    << setw(14) << attributes.n_files
    << " " << path << endl;
}

Attributes explore(const directory_entry& directory){
    Attributes attributes{};
    for (const auto& entry : recursive_directory_iterator{directory.path()}) {
        if(entry.is_directory()){
            attributes.n_directories++;
        } else {
            attributes.n_files++;
            attributes.size_bytes += entry.file_size();
        }
    }
    return attributes;
}

// 传递一个目录路径作为参数
int main(int argc, const char** argv) {
    if (argc != 2){
        cerr << "Usage: " << argv[0] << " <path>\n";
        return -1;
    }
    const path sys_path{argv[1]};
    cout <<"Size    Files    Dirs    Name\n";
    cout <<"---------------------------------\n";
    Attributes root_attributes{};
    for (const auto& entry : directory_iterator{sys_path}){
        try {
            if (entry.is_directory()) {
                const auto attributes = explore(entry);
                root_attributes += attributes;
                print_line(attributes, entry.path().string());
                root_attributes.n_directories++;
            } else {
                root_attributes.n_files++;
                error_code ec;
                root_attributes.size_bytes += entry.file_size(ec);
                if (ec) {
                    cerr << "Error reading file size: " << entry.path().string() << " " << ec.message() << endl;
                }
                cout << "Error: " << entry.path().string() << " is not a directory\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    print_line(root_attributes, sys_path.string());

    return 0;
}