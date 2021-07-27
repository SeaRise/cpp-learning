#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

// 4.21
void oddMultiplyByTwo() {
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &item : vec) {
        item = (item % 2 == 1) ? (2 * item) : item;
    }
    for (const auto &item : vec) {
        cout << item << " ";
    }
    cout << endl;
}

// 4.22
void splitLevel() {
    vector<int> vec{0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    vector<string> levels1;
    levels1.resize(10);
    for (const auto &grade : vec) {
        levels1.emplace_back(grade < 60 ? "fail" : (grade < 75 ? "low pass" : (grade < 90 ? "pass" : "high pass")));
    }
    for (const auto &level : levels1) {
        cout << level << " ";
    }
    cout << endl;

    vector<string> levels2;
    levels2.resize(10);
    for (const auto &grade : vec) {
        if (grade < 60) {
            levels2.emplace_back("fail");
        } else if (grade < 75) {
            levels2.emplace_back("low pass");
        } else if (grade < 90) {
            levels2.emplace_back("pass");
        } else {
            levels2.emplace_back("high pass");
        }
    }
    for (const auto &level : levels2) {
        cout << level << " ";
    }
    cout << endl;
}

int main() {

    // 4.21
    oddMultiplyByTwo();

    // 4.22
    splitLevel();

    return 0;
}