#ifndef CPP_LEARNING_SALES_DATA_H
#define CPP_LEARNING_SALES_DATA_H

#include <string>
#include <iostream>
#include <utility>
#include <stdexcept>

class Sales_data {
    friend std::ostream &print(std::ostream &ostream, const Sales_data &data);
    friend std::istream &read(std::istream &istream, Sales_data &data);

public:
    Sales_data() = default;
    Sales_data(std::string s, unsigned n, double p)
            : bookNo(std::move(s)), sold(n), revenue(p*n) {}
    explicit Sales_data(std::string s)
        : Sales_data(std::move(s), 0, 0.0) {}
    explicit Sales_data(std::istream &is);

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &);

private:
    std::string bookNo;
    unsigned sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    sold += rhs.sold;
    revenue += rhs.revenue;
    return *this;
}

std::ostream &print(std::ostream &ostream, const Sales_data &data) {
    return ostream << data.bookNo << " " << data.sold << " " << data.revenue;
}

std::istream &read(std::istream &istream, Sales_data &data) {
    double price = 0;
    istream >> data.bookNo >> data.sold;
    data.revenue = price * data.sold;
    return istream;
}

Sales_data::Sales_data(std::istream &is) : Sales_data() {
    if (!read(is, *this)) {
        throw std::runtime_error("No data?!");
    };
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif //CPP_LEARNING_SALES_DATA_H
