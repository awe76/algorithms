#include <iostream>

void reset(int &t) {
    t = 0;
}

int main() {
    int n = 5;
    reset(n);

    std::cout << n << std::endl;
}