//
// Created by searise on 7/24/21.
//

#ifndef CPP_LEARNING_SALES_DATA_H
#define CPP_LEARNING_SALES_DATA_H


#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned int sold = 0;
    double revenue = 0.0;

    void print();
};

void Sales_data::print() {
    std::cout << bookNo << " " << sold
              << " " << revenue << std::endl;
}


#endif //CPP_LEARNING_SALES_DATA_H
