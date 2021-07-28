#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void foreach(const vector<int> &list, decltype(list.size()) index = 0) {
    if (index != list.size()) {
        cout << list[index] << endl;
        foreach(list, index + 1);
    }
}

int main() {
    foreach({1, 2, 3, 4, 5, 6, 7, 8, 9});
}