#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "StrBlob.h"

using std::string;
using std::vector;
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

int main() {
    string file("../cpp_primer_5/data/input.txt");
    std::ifstream ifs(file);
    if (ifs) {
        StrBlob blob;
        for (std::string str; std::getline(ifs, str); blob.push_back(str));
        for (auto pbeg(blob.begin()), pend(blob.end()); !pbeg.equalsTo(pend); pbeg.incr()) {
            std::cout << pbeg.deref() << std::endl;
        }
        for (auto pbeg(blob.cbegin()), pend(blob.cend()); !pbeg.equalsTo(pend); pbeg.incr()) {
            std::cout << pbeg.deref() << std::endl;
        }
    } else {
        cerr << "no open file: " << file << endl;
    }
    return 0;
}