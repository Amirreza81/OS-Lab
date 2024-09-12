#include <iostream>
#include <sstream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <string>


using namespace std;
namespace fs = std::filesystem;

string readinggg(const string& path) {
    ifstream file(path);
    if (file.is_open()) {
        stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
    return "";
}

string memreadd(const string& pid) {
    string path = "/proc/" + pid + "/status";
    ifstream file(path);
    string line;
    while (getline(file, line)) {
        if (line.find("VmRSS:") != string::npos) {
            return line.substr(line.find_last_of('\t') + 1);
        }
    }
    return "N/A";
}

vector<string> readdcmd(const string& pid) {
    string path = "/proc/" + pid + "/cmdline";
    string cmd = readinggg(path);
    vector<string> args;
    stringstream ss(cmd);
    string arg;
    while (getline(ss, arg, '\0')) {
        args.push_back(arg);
    }
    return args;
}

vector<string> readenvv(const string& pid) {
    string path = "/proc/" + pid + "/environ";
    string env = readinggg(path);
    vector<string> vars;
    stringstream ss(env);
    string var;
    while (getline(ss, var, '\0')) {
        vars.push_back(var);
    }
    return vars;
}

int main(int argc, char* argv[]) {
    string pid = argv[1];
    string comm = "/proc/" + pid + "/comm";
    string name = readinggg(comm);
    cout << "Name: " << name << endl;
    string memory = memreadd(pid);
    vector<string> args = readdcmd(pid);
    cout << "Memory: " << memory << endl;
    vector<string> vars = readenvv(pid);
    cout << "Args: ";
    for (const string& arg : args) {
        cout << arg << " ";
    }
    cout << endl;
    cout << "Vars: " << endl;
    for (const string& var : vars) {
        cout << var << endl;
    }
    return 0;
}
