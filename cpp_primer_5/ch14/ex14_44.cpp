#include <iostream>
#include <map>
#include <functional>

using std::string;
using std::map;
using std::function;
using std::cin;
using std::cout;
using std::endl;

int minus(int i, int j) {
    return i - j;
}

class divide {
public:
    int operator()(int i, int j) {
        return i / j;
    }
};

int main() {

    auto mod = [](int i, int j) { return i % j; };

    map<string, function<int(int, int)>> binaryOps = {
            {"+", [](int i, int j) { return i + j; }}, // 匿名lambda
            {"-", &minus}, // 函数指针
            {"*", std::multiplies<>()}, // 标准库函数对象
            {"/", divide()}, // 普通的函数对象
            {"%", mod} // 命名lambda
    };

    int l, r;
    string op;
    while (cin >> l >> op >> r) {
        auto res = binaryOps.find(op);
        if (res != binaryOps.end()) {
            cout << "result: " << res->second(l, r) << endl;
        } else {
            cout << "unknown operator: " << op << endl;
        }
    }

    return 0;
}