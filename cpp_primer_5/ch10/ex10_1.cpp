#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    // 10.1
    vector<int> vec{0, 1, 1, 2, 3, 4, 5, 6, 7,8 ,9 ,10};
    cout << std::count(vec.cbegin(), vec.cend(), 1) << endl;

    // 10.2
    string s{"01123456789"};
    cout << std::count(s.cbegin(), s.cend(), '1') << endl;

    return 0;
}