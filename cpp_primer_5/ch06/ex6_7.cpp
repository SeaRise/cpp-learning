#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int countUsed() {
    static size_t count = 0;
    return count++;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        cout << countUsed() << " ";
    }
    cout << endl;
}