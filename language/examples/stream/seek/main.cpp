#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

ifstream open(const char* path, ios_base::openmode model = ios_base::in) {
    ifstream file {path};
    if (!file.is_open())
    {
        string err{"Unable to open file"};
        err.append(path);
        throw runtime_error{err};
    }
    return file;
}

int main()
{
    try {
        auto intro = open("introspection.txt");
        cout <<"Content: " << intro.rdbuf() << endl;
        intro.seekg(0);
        cout <<"Counts after seekg(0): " << intro.rdbuf() << endl;
        intro.seekg(-4, ios_base::end);
        cout << "tellg() after seekg(-4, ios_base::end): " << intro.tellg() << endl;
        cout <<"Contents after seekg(-4, ios_base::end): " << intro.rdbuf() << endl;
    } catch(const exception& e){
        cerr << e.what();
    }
}