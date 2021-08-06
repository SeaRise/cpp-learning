#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::istream;
using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

// 8.4
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

// 8.5
vector<string> &readWords(vector<string> &vec, const string &file) {
    std::ifstream ifs(file);
    if (ifs) {
        string buf;
        while (ifs >> buf) {
            vec.push_back(buf);
        }
    } else {
        cerr << "no open file: " << file << endl;
    }
    return vec;
}

int main() {
    vector<string> vec;
    string file("../cpp_primer_5/data/input.txt");

    // 8.4
    for (const auto &line : readLines(vec, file)) {
        cout << line << endl;
    }

    cout << endl;
    vec.clear();

    // 8.5
    for (const auto &word : readWords(vec, file)) {
        cout << word << endl;
    }

    return 0;
}