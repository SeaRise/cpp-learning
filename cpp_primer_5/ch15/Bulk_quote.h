#ifndef CPP_LEARNING_BULK_QUOTE_H
#define CPP_LEARNING_BULK_QUOTE_H

#include <utility>

#include "Quote.h"

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(std::string book, double sales_price, size_t qty, double disc)
            : Quote(std::move(book), sales_price), min_qty(qty), discount(disc) {}
    double net_price(std::size_t n) const override {
        double basePrice = Quote::net_price(n);
        return n >= min_qty ? (1 - discount) * basePrice : basePrice;
    }
    Quote *clone() const & override { return new Bulk_quote(*this); }
    Quote *clone() && override { return new Bulk_quote(std::move(*this)); }
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

#endif //CPP_LEARNING_BULK_QUOTE_H
