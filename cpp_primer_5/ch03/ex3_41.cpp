#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;

int main() {
    // 3.41
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec(begin(arr), end(arr));
    for (const auto &item : vec) {
        cout << item << " ";
    }
    cout << endl;

    // 3.42
    const auto size = vec.size();
    int copyArr[size];
    for (int i = 0; i < size; ++i) {
        copyArr[i] = vec[i];
    }
    for (const auto &item : copyArr) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}