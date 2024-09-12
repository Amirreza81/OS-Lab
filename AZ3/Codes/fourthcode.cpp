#include <iostream>
#include <fstream>
#include <string>
int main() {
    std::ifstream meminfo("/proc/meminfo");
    std::string line;
    long tmem = 0;
    long fmem = 0;
    while (std::getline(meminfo, line)) {
        if (line.find("MemTotal:") != std::string::npos) {
            tmem = std::stol(line.substr(line.find(":") + 1));
        } else if (line.find("MemFree:") != std::string::npos) {
            fmem = std::stol(line.substr(line.find(":") + 1));
        }
    }
    long umem = tmem - fmem;
    std::cout << "Total Memory(MB): " << tmem / 1024 << std::endl;
    std::cout << "Used Memory(MB): " << umem / 1024 << std::endl;
    std::cout << "Free Memory(MB): " << fmem / 1024 << std::endl;

    return 0;
}