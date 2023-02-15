#include <iostream>
#include "fact.h"

int main() {
    int n;
    std::cin >> n;

    int f = fact(n);
    std::cout << f << std::endl;
}
