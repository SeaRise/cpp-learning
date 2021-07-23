#include <iostream>

int main() {
    // 1.3
    std::cout << "Hello, World" << std::endl;

    // 1.4
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << std::endl;
}