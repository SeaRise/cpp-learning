#include <iostream>

// 1.9
void sum() {
    int sum = 0, var = 50;
    while (var <= 100) {
        sum += var++;
    }
    std::cout << sum << std::endl;
}

// 1.10
void print() {
    int var = 10;
    while (var >= 0) {
        std::cout << var-- << " ";
    }
    std::cout << std::endl;
}

// 1.11
void range() {
    std::cout << "Enter two numbers:" << std::endl;
    int min = 0, max = 0;
    std::cin >> min >> max;
    if (max < min) {
        int tmp = min;
        min = max;
        max = tmp;
    }
    int var = min;
    while (var <= max) {
        std::cout << var++ << " ";
    }
    std::cout << std::endl;
}

// 1.13
void again() {
    int sum = 0;
    for (int i = 50; i <= 100; ++i) {
        sum += i;
    }
    std::cout << sum << std::endl;

    for (int i = 10; i >= 0; --i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Enter two numbers:" << std::endl;
    int min = 0, max = 0;
    std::cin >> min >> max;
    if (max < min) {
        int tmp = min;
        min = max;
        max = tmp;
    }
    for (int i = min; i <= max; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// 1.16
void rangeSum() {
    int sum = 0, var = 0;
    while (std::cin >> var) {
        sum += var;
    }
    std::cout << sum << std::endl;
}

int main() {
    // 1.9
    sum();

    // 1.10
    print();

    // 1.11
    range();

    // 1.13
    again();

    // 1.16
    rangeSum();
}