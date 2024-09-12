#include <bits/stdc++.h>
using namespace std;
int main() {
    fstream read_file;
    read_file.open("/proc/version", ios::in);
    if (!read_file.is_open()) {
        perror("Error!");
        return 1;
    }
    fstream read_file2;
    read_file2.open("./Linux Version.txt", ios::out | ios::app);
    if (!read_file2.is_open()) {
        perror("Error!");
        return 1;
    }
    string line;
    while (!read_file.eof()) {
        getline(read_file, line);
        read_file2 << line;
    }
    return 0;
}