#include <iostream>
#include <filesystem>
#include <iomanip>

using namespace std;
using namespace std::filesystem;
using namespace std::chrono;

void describe(const directory_entry& entry){
    try {
        if(entry.is_directory()){
            cout <<"        *";

        }else {
            cout <<setw(12) << entry.file_size();
        }
        const auto lw_time = duration_cast<seconds>(entry.last_write_time().time_since_epoch());
        cout << setw(12) << lw_time.count() << " " << entry.path().filename().string() << endl;
    }catch (const filesystem_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

// 传递一个目录路径作为参数
int main(int argc, const char** argv) {
    if (argc != 2){
        cerr << "Usage: " << argv[0] << " <path>\n";
        return -1;
    }
    const path sys_path{argv[1]};
    cout <<"Size    Last Write Name\n";
    cout <<"---------------------------------\n";
    for (const auto& entry : directory_iterator{sys_path}){
        describe(entry);
    }
    return 0;
}