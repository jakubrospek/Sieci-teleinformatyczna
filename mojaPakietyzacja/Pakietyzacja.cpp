#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
struct header
{
    int offset;
    int size;
};
 
int main()
{
    //const char *path = "E:\\uczelnia.zip";
    char* byte_array = NULL;
    int file_size;
    int write_file_size;
    int package_size = 2048;
 
    ifstream file;
    file.open("W3.jpg", ios::binary);
    if(!file) {
        cerr << "File open error" << "\n";
        exit(1);
    }
    file.seekg(0, ios::end);
    file_size = file.tellg();
    file.seekg(0, ios::beg);
    write_file_size = file_size;
 
    //cout << "File path: " << path << "\n";
    cout << "File size: " << file_size << "\n";
    // get number of packages
    int num_packages = file_size / package_size;
    if(file_size % package_size != 0) ++num_packages;
 
    // allocate byte array storage in RAM
    try {
        byte_array = new char[file_size + num_packages * sizeof(header)];
    } catch(bad_alloc&) {
        cerr << "Allocation error" << "\n";
        exit(1);
    }
 
    vector<header*> packages;
    // point the end of last package
    header* header_addr;
    for(int i = 0; i < num_packages; ++i) {
        if(file_size >= package_size) {
            // poczatek_tablicy_bajtow + ilosc_zapisanych_bajtow + ilosc zapisanych naglowkow: prawdziwe dla i => 1
            // poczatek_tablicy_bajtow: prawdziwe dla i = 0
            if(i >= 1)
                header_addr = ( (header*) byte_array + (write_file_size - file_size) + (i + 1) * sizeof(header) );
            else
                header_addr = (header*) byte_array;
            header_addr->offset = (int) header_addr;
            header_addr->size = package_size;
            /*
             * Write package address to vector.
             */
            packages.push_back(header_addr);
            /*
             * Write data to package.
             */
            file.read((char*) header_addr + sizeof(header), package_size);
            file_size -= package_size;
        } else {
            // last package can be smaller (file_size)
        }
    }
    file.close();
 
    delete[] byte_array;
    return 0;
}
