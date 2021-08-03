#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<char> vec{'a', 'e', 'i', 'o', 'u'};
    string str(vec.cbegin(), vec.cend());
    cout << str << endl;
    return 0;
}