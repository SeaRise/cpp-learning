#include <iostream>
#include <string>

#include "Token.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    Token token;
    token = 'a';
    cout << token << endl;
    token = 1;
    cout << token << endl;
    token = 1.1;
    cout << token << endl;
    token = "union";
    cout << token << endl;
    return 0;
}