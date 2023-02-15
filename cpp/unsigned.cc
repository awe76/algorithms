#include <iostream>

int main() {
    unsigned u1 = 10, u2 = 42, u3 = 11;
    int i1 = 10;

    std::cout << u1 - u2 << std::endl;
    std::cout << i1 - u1 << std::endl;
    std::cout << u1 - u3 << std::endl;

    int i = 2;
    const int i2 = i, &r = i;

    const int *const p3 = &i;

    const int *p1 = &i;


    // const int v2 = 0;
    const int ic = 5;
    const int &r1 = ic;

    // r1 = v2;

    std::cout << i2 + r + *p3 + r1 + p1 << std::endl;

    return 0;
}
