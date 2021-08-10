#include <iostream>

#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: "
       << ret << endl;
    return ret;
}

// 15.2, 15.5, 15.6, 15.7
int main() {
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);
    Limit_quote lq("textbook", 10.60, 10, 0.3);

    print_total(std::cout, q, 12);
    print_total(std::cout, bq, 12);
    print_total(std::cout, lq, 12);
    return 0;
}