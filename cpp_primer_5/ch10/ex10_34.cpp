#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8,9};
    // 10.34
    std::for_each(vec.crbegin(), vec.crend(), [](const int i) {
        cout << i << " ";
    });
    cout << endl;

    // 10.35
    for (auto it = std::prev(vec.cend()); true; --it) {
        std::cout << *it << " ";
        if (it == vec.cbegin()) {
            break;
        }
    }
    std::cout << std::endl;

    // 10.36
    std::list<int> list = {0, 1, 2, 3, 4, 5, 0, 6, 7, 8,9};
    auto findIter = std::find(list.crbegin(), list.crend(), 0);
    std::cout << std::distance(findIter, list.crend()) << std::endl;

    // 10.37
    std::list<int> list2;
    std::copy(vec.crbegin() + 2, std::prev(vec.crend()) - 2, std::back_inserter(list2));
    std::for_each(list2.cbegin(), list2.cend(), [](const int i) { cout << i << ' '; });
    cout << endl;

    return 0;
}