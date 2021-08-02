#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::string;
using std::istream;
using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

vector<string> &readLines(vector<string> &vec, const string &file) {
    std::ifstream ifs(file);
    if (ifs) {
        string buf;
        while (getline(ifs, buf)) {
            vec.push_back(buf);
        }
    } else {
        cerr << "no open file: " << file << endl;
    }
    return vec;
}

int main() {
    vector<string> vec;
    string file("./cpp_primer_5/data/input.txt");

    string buf;
    for (const auto &line : readLines(vec, file)) {
        std::istringstream iss(line);
        while (iss >> buf) {
            cout << buf << endl;
        }
    }

    return 0;
}