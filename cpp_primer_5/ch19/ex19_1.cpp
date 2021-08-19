#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

void *operator new(size_t size) {
    cout << "my new" << endl;
    void *mem = malloc(size);
    return mem ? mem : throw std::bad_alloc();
}

void operator delete(void *mem) noexcept {
    cout << "my delete" << endl;
    free(mem);
}

int main() {
    auto *p = new string("test");
    cout << *p << endl;
    delete p;
    return 0;
}