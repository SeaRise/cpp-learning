#include <iostream>
#include "StrBlob.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    const StrBlob csb{ "hello", "world", "pezy" };
    StrBlob sb{ "hello", "world", "Mooophy" };

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "pezy";
    std::cout << sb.front() << " " << sb.back() << std::endl;
    return 0;
}