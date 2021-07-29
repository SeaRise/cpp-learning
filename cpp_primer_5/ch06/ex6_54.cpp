#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

typedef int (*fp) (int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main() {
    vector<fp> vector{&add, &subtract, &multiply, &divide};

    int a = 10;
    int b = 5;
    for (auto item : vector) {
        cout << item(a, b) << " ";
    }
    cout << endl;

    return 0;
}