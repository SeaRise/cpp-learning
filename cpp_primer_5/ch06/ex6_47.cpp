#include <iostream>
#include <vector>
#define NDEBUG
#include <cassert>

using std::cout;
using std::endl;
using std::vector;

void foreach(const vector<int> &list, decltype(list.size()) index = 0) {
    if (index != list.size()) {
        cout << list[index] << endl;
        assert(1 < 0);
#ifndef NDEBUG
        cout << "vector size: " << list.size() << endl;
        std::cout << __func__ << std::endl;
        std::cout << __FILE__ << std::endl;
        std::cout << __LINE__ << std::endl;
        std::cout << __TIME__ << std::endl;
        std::cout << __DATE__ << std::endl;
#endif
        foreach(list, index + 1);
    }
}

int main() {
    foreach({1, 2, 3, 4, 5, 6, 7, 8, 9});
}