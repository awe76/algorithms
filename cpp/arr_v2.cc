#include <iostream>

int main() {
    int test[5] = {1, 5, 6, 7, 9};

    for (int i = 0; i < 5; i++)
        *(test +i) = 0;

    for (auto n: test) 
        std::cout << n << std::endl;
}