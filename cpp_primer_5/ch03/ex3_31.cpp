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

// 3.31
void setIndexArr() {
    int array[10];
    for (int i = 0; i < 10; ++i) {
        array[i] = i;
    }
    for (const auto &item : array) {
        cout << item << " ";
    }
    cout << endl;
}

// 3.32
void setIndexVec() {
    int array[10];
    vector<int> vec(begin(array), end(array));
    for (int i = 0; i < 10; ++i) {
        vec[i] = i;
    }
    for (const auto &item : vec) {
        cout << item << " ";
    }
    cout << endl;
}

// 3.35
void setZeroArr() {
    int arr[10];
    for (auto iter = begin(arr); iter < end(arr); ++iter) {
        *iter = 0;
    }
    for (const auto &item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

bool isEquals(int * const begin1, const int * const end1, int * const begin2, const int * const end2) {
    if ((end1 - begin1) != (end2 - begin2)) {
        return false;
    }

    for (int *it1 = begin1, *it2 = begin2; it1 != end1 && it2 != end2; ++it1, ++it2) {
        if (*it1 != *it2) {
            return false;
        }
    }

    return true;
}

void checkEquals() {
    int arr1[10] = {};
    int arr2[10] = {};
    cout << isEquals(begin(arr1), end(arr1), begin(arr2), end(arr2)) << endl;

    vector<int> vec1(begin(arr1), end(arr1));
    vector<int> vec2(begin(arr2), end(arr2));
    cout << (vec1 == vec2) << endl;
}

int main() {
    // 3.31
    setIndexArr();

    // 3.32
    setIndexVec();

    // 3.33
    // 数组不初始化，那么元素的值可能是任意的.

    // 3.35
    setZeroArr();

    // 3.36
    checkEquals();

    return 0;
}