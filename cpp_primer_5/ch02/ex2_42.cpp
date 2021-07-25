#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data salesData;
    std::cin >> salesData.bookNo >> salesData.sold >> salesData.revenue;
    salesData.print();
    return 0;
}