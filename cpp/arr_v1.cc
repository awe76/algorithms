#include <iostream>

int main() {
    int src[10];
    for (unsigned i = 0; i < 10; i++) 
        src[i] = i;

    for (auto item: src) 
        std::cout << item << std::endl;

    return 0;
}