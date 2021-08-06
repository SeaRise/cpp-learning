#include <iostream>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

int main() {
    size_t n = 10;
    std::allocator<string> alloc;
    string * const p = alloc.allocate(10);
    string buf;
    string *q = p;
    while (cin >> buf && q != p + n) {
        alloc.construct(q++, buf);
    }
    while (q != p) {
        cout << *--q << endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
    return 0;
}