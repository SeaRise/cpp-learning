#ifndef CPP_LEARNING_QUOTE_H
#define CPP_LEARNING_QUOTE_H

#include <utility>
#include <string>

class Quote {
public:
    Quote() = default;
    // 这里如果传给book的是，右值引用，那么有string book(std::move(input)), 事实上触发的是string的移动构造函数, 没有发生拷贝.
    Quote(std::string book, double sales_price) :
        bookNo(std::move(book)), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

#endif //CPP_LEARNING_QUOTE_H
