#include <iostream>

int main() {
    std::cout << "Enter the range of two numbers:" << std::endl;
    int from = 0, to = 0;
    std::cin >> from >> to;
    while (from <= to) {
        std::cout << from << std::endl;
        from++;
    }

    return 0;
}