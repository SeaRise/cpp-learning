#include <iostream>
#include <string>

#include "Vec.h"

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
    Vec<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    for (auto iter = vec.begin(); iter < vec.end(); ++iter) {
        cout << *iter << endl;
    }
    for (const auto &item : vec) {
        cout << item << endl;
    }

    Vec<string> vec2;
    vec2.push_back("f");
    vec2.push_back("u");
    vec2.push_back("c");
    vec2.push_back("k");
    for (auto iter = vec2.begin(); iter < vec2.end(); ++iter) {
        cout << *iter << endl;
    }
    for (const auto &item : vec2) {
        cout << item << endl;
    }
    return 0;
}