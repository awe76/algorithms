#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item sum, item;
    while (std::cin >> item) {
        if (sum.isbn() == "") {
            sum = item;
        } else {
            sum += item;
        }
    }

    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}