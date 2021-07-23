#include <iostream>
#include "../include/Sales_item.h"

// 1.20, 1.21, 1.22
int enterAndSum() {
    std::cout << "enter sales_item:" << std::endl;
    Sales_item item, sum;
    if (std::cin >> sum) {
        while (std::cin >> item) {
            std::cout << item << std::endl;
            if (item.isbn() == sum.isbn()) {
                sum += item;
            } else {
                std::cerr << "diff sbin?!" << std::endl;
                return -1;
            }
        }
        std::cout << sum << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}

// 1.23, 1.24
int enterAndCount() {
    std::cout << "enter sales_item:" << std::endl;
    Sales_item cur;
    int count = 1;
    if (std::cin >> cur) {
        auto curSbin = cur.isbn();
        while (std::cin >> cur) {
            if (curSbin == cur.isbn()) {
                ++count;
            } else {
                std::cout << "count of " << curSbin << " = " << count << std::endl;

                curSbin = cur.isbn();
                count = 1;
            }
        }
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}

int main()
{
    // 1.20, 1.21, 1.22
    if (enterAndSum() == -1) {
        return -1;
    }

    // 1.23, 1.24
    if (enterAndCount() == -1) {
        return -1;
    }

    return 0;
}