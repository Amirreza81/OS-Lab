#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream cpuinfo("/proc/cpuinfo");
    string line;
    string model;
    string freq;
    string cache;

    while (getline(cpuinfo, line)) {
        if (line.find("cache size") != string::npos) {
            cache = line.substr(line.find(":") + 2);
        }  else if (line.find("cpu MHz") != string::npos) {
            freq = line.substr(line.find(":") + 2) + " MHz";
        } else if (line.find("model name") != string::npos) {
            model = line.substr(line.find(":") + 2);
        }
    }
    cpuinfo.close();
    cout << "Model Name: " << model << endl;
    cout << "CPU MHz: " << freq << endl;
    cout << "Cache Size: " << cache << endl;
    return 0;
}