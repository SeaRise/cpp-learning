#include "iostream"
#include "string"
#include "cctype"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    // 3.6
    string str("test for ex3_6");
    for (auto &c : str) {
        c = 'X';
    }
    cout << str << endl;

    // 3.10
    cout << "Enter a string of characters including punctuation." << endl;
    for (string s; getline(cin, s); cout << endl) {
        for (const auto &c : s) {
            if (!ispunct(c)) {
                cout << c;
            }
        }
    }
    return 0;
}