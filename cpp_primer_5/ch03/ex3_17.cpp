#include "iostream"
#include "string"
#include "vector"
#include "cctype"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

// 3.17
void toupper() {
    vector<string> vec;
    for (string input; cin >> input && input != "exit"; vec.push_back(input));
    for (auto &item : vec) {
        for (auto &c : item) {
            c = toupper(c);
        }
    }
    for (const auto &item : vec) {
        cout << item << endl;
    }
}

// 3.20
void sum() {
    vector<int> vec;
    for (int input; cin >> input; vec.push_back(input));
    if (vec.empty()) {
        return;
    }
    if (vec.size() == 1) {
        cout << vec[0] + vec[0] << endl;
        return;
    }
    auto tail = vec.size() - 1;
    decltype(vec.size()) head = 0;
    while (head <= tail) {
        --tail;
        ++head;
        cout << vec[head] + vec[tail] << endl;
    }
}

int main() {
    // 3.17
    toupper();

    // 3.20
    sum();

    return 0;
}
