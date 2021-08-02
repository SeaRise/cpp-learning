#include <iostream>

using std::string;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::flush;

istream &print(istream &is) {
    string buf;
    while (!(is >> buf).eof()) {
        cout << buf << endl;
    }
    cout << flush;
    is.clear();
    return is;
}

int main() {
    print(cin);
    return 0;
}