#include <iostream>
#include <string>
#include <utility>

using std::ostream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

template<typename T, typename ...Args>
void foo(T t, Args ...args) {
    std::cout << sizeof...(Args) << "\t";
    std::cout << sizeof...(args) << std::endl;
}

template<typename T>
ostream &print(ostream &os, const T &t) {
    return os << t;
}
// 递归中间函数
template<typename T, typename ... Args>
ostream &print(ostream &os, const T &t, const Args& ... args) {
    os << t << ", ";
    print(os, args...);
}

int main() {
    // 16.51, 16.52
    foo(1, 2);
    foo(1, 23, 4, 5, 6);

    // 16.53
    print(cout, 5, "fdfd", 5.5);

    return 0;
}