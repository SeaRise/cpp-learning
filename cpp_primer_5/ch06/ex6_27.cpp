#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int sum(initializer_list<int> list) {
    int sum = 0;
    for (auto item : list) {
        sum += item;
    }
    return sum;
}

int main() {
    cout << sum({1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;
}