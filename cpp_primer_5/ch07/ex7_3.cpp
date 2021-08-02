#include <iostream>
#include <stdexcept>
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"
#include "Debug.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main() {
    try {
        Sales_data total(cin);
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } catch (const std::runtime_error &e) {
        cerr << e.what() << endl;
    }
}