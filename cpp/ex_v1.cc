#include <iostream>
#include <stdexcept>

int main() {
    int a, b, c;
    try {
        std::cin >> a >> b;
        c = a / b;
        std::cout << "result: " << c << std::endl;
    } catch (const char *err) {
        std::cout << "exception: " << err << std::endl;
    }

    return 0;
}