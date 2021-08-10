#ifndef CPP_LEARNING_LIMIT_QUOTE_H
#define CPP_LEARNING_LIMIT_QUOTE_H

#include <utility>
#include <string>

#include "Quote.h"

class Limit_quote : public Quote {
public:
    Limit_quote() = default;
    Limit_quote(std::string book, double sales_price, size_t l, double disc)
            : Quote(std::move(book), sales_price), limit(l), discount(disc) {}
    double net_price(std::size_t n) const override {
        std::size_t discN = std::min(n, limit);
        double overPrice = Quote::net_price(n - discN);
        double discBasePrice = Quote::net_price(discN);
        return overPrice + discBasePrice * (1 - discount);
    }
private:
    std::size_t limit = 0;
    double discount = 0.0;
};

#endif //CPP_LEARNING_LIMIT_QUOTE_H
