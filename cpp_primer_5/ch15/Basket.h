//
// Created by searise on 8/11/21.
//

#ifndef CPP_LEARNING_BASKET_H
#define CPP_LEARNING_BASKET_H

#include <memory>
#include <set>

#include "Quote.h"

class Basket {
public:
    Basket &add_item(const Quote &sale) {
        add_item(std::shared_ptr<Quote>(sale.clone()));
        return *this;
    }
    Basket & add_item(Quote &&sale) {
        add_item(std::shared_ptr<Quote>(std::move(sale).clone()));
        return *this;
    }
    Basket & add_item(const std::shared_ptr<Quote> &sale) {
        items.insert(sale);
        return *this;
    }
    double total_receipt() const {
        double sum = 0.0;
        for (auto iter = items.cbegin(); iter != items.cend() ; iter = items.upper_bound(*iter)) {
            sum += (*iter)->net_price(items.count(*iter));
        }
        return sum;
    }
private:
    static
    bool compare(const std::shared_ptr<Quote> &lhs,
                 const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{&compare};
};

#endif //CPP_LEARNING_BASKET_H
