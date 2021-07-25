#include "iostream"
#include "string"
#include "vector"
#include "cctype"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

// 3.23
void multiplyTwo() {
    vector<int> vec;
    vec.reserve(10);
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }
    for (auto iter = vec.begin(); iter < vec.end(); ++iter) {
        *iter = 2 * *iter;
    }
    for (const auto &item : vec) {
        cout << item << " ";
    }
    cout << endl;
}

// 3.24
void sum() {
    vector<int> vec;
    for (int input; cin >> input; vec.push_back(input));
    if (vec.empty()) {
        return;
    }
    if (vec.size() == 1) {
        cout << *vec.begin() * 2 << endl;
        return;
    }
    auto tail = vec.end() - 1;
    auto head = vec.begin();
    while (head <= tail) {
        --tail;
        ++head;
        cout << *head + *tail << endl;
    }
}

void sores() {
    vector<unsigned> vector(11, 0);
    unsigned grade;
    auto iter = vector.begin();
    while (cin >> grade) {
        if (grade <= 100) {
            ++(*(iter + grade / 10));
        }
    }
    for (const auto &item : vector) {
        cout << item << endl;
    }
}

int main() {
    // 3.23
    multiplyTwo();

    // 3.24
    sum();

    // 3.25
    sores();

    return 0;
}