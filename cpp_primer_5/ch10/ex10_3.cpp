#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    // 10.3
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7,8 ,9};
    cout << std::accumulate(vec.cbegin(), vec.cend(), 0) << endl;
    return 0;
}