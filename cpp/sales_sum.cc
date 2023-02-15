#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item v1, v2;

    std::cout << "Enter two sales to sum:" << std::endl;
    std::cin >> v1 >> v2;
    std::cout << std::endl << "Sum is " << v1 + v2 << std::endl;
    return 0;
}