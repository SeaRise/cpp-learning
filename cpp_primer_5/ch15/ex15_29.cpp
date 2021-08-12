#include <iostream>
#include <vector>
#include <memory>
#include <numeric>

#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
#include "Basket.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);
    Limit_quote lq("textbook", 10.60, 10, 0.3);

    vector<std::shared_ptr<Quote>> vec;
    vec.push_back(std::make_shared<Quote>(q));
    vec.push_back(std::make_shared<Quote>(bq));
    vec.push_back(std::make_shared<Quote>(lq));

    // 15.29
    auto n = 12;
    auto sum = std::accumulate(vec.cbegin(), vec.cend(), 0.0,
        [n](double a, const std::shared_ptr<Quote>& ptr) { return a +  ptr->net_price(n); });
    cout << sum << endl;

    // 15.30
    Basket basket;
    for (int i = 0; i < 12; ++i) {
        basket.add_item(q).add_item(bq).add_item(lq);
    }
    cout << basket.total_receipt() << endl;

    return 0;
}