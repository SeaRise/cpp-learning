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
    return 0;
}