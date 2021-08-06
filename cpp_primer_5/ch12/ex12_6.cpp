#include <iostream>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;
using std::cin;
using std::cout;
using std::endl;

void read1(std::istream &is, vector<int> *vecPtr) {
    int buf;
    while (is >> buf) {
        vecPtr->push_back(buf);
    }
}

void println1(std::ostream &os, vector<int> *vecPtr) {
    for (const auto &i : *vecPtr) {
        os << i << " ";
    }
    os << endl;
}

void readAndPrintln1() {
    auto p = new vector<int>();
    read1(cin, p);
    println1(cout, p);
    delete p;
}

void read2(std::istream &is, const shared_ptr<vector<int>>& vecPtr) {
    int buf;
    while (is >> buf) {
        vecPtr->push_back(buf);
    }
}

void println2(std::ostream &os, const shared_ptr<vector<int>>& vecPtr) {
    for (const auto &i : *vecPtr) {
        os << i << " ";
    }
    os << endl;
}

void readAndPrintln2() {
    auto p = std::make_shared<vector<int>>();
    read2(cin, p);
    println2(cout, p);
}

int main() {
    // 12.6
//    readAndPrintln1();
    // 12.7
//    readAndPrintln2();
    return 0;
}