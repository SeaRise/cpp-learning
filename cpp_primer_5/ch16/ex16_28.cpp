#include <iostream>
#include <string>
#include <utility>

#include "my_ptr.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

class TestPtr {
public:
    explicit TestPtr(const std::string &str): content(str) {}
    explicit TestPtr(std::string &&str): content(std::move(str)) {}
    ~TestPtr() { cout << "free " << content << endl; }
    string content;
};

void printTestPtr(my_shared_ptr<TestPtr> sharedPtr) {
    cout << sharedPtr->content << endl;
}

int main() {
    // 16.28
    my_shared_ptr<TestPtr> sharedPtr = make_my_shared_ptr<TestPtr>(TestPtr("test1"));
    sharedPtr = sharedPtr;
    printTestPtr(sharedPtr);
    my_unique_ptr<TestPtr> uniquePtr(new TestPtr("test2"));
    cout << uniquePtr->content << endl;

    return 0;
}