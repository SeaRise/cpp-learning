#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "DebugDelete.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

template<typename T> void print1(std::vector<T> vec) {
    for (typename std::vector<T>::size_type i = 0; i != vec.size(); ++i) {
        cout << vec[i] << "\t";
    }
    cout << endl;
}

template<typename T> void print2(std::vector<T> vec) {
    for (typename std::vector<T>::const_iterator iter = vec.cbegin(); iter != vec.cend(); ++iter) {
        cout << *iter << "\t";
    }
    cout << endl;
}

int main() {
    // 16.19
    std::vector<string> vec{"f", "u", "c", "k"};
    print1(vec);
    print2(vec);

    // 16.21
    int *p = new int(5);
    cout << *p << endl;
    DebugDelete()(p);

    std::unique_ptr<int, DebugDelete> ptr(new int(6), DebugDelete());
    cout << *ptr << endl;
    return 0;
}