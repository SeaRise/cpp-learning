#include <iostream>
#include <string>
#include <fstream>

#include "Blob.h"

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
    string file("../cpp_primer_5/data/input.txt");
    std::ifstream ifs(file);
    if (ifs) {
        Blob<string> blob;
        for (std::string str; std::getline(ifs, str); blob.push_back(str));
        for (auto pbeg = blob.begin(), pend = blob.end(); pbeg != pend; ++pbeg) {
            std::cout << *pbeg << std::endl;
        }
    } else {
        cerr << "no open file: " << file << endl;
    }
    return 0;
}