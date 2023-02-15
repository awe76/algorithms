#include <iostream>

int main() {
    int ia[3][4] = {
        {1, 4, 6, 7},
        {4, 7, 9, 0},
        {7, 5, 7, 8}
    };

    for (int (*row)[4] = ia; row != ia + 3; ++row) {
        for (int *item = *row; item != *row + 4; ++item) {
            std::cout << *item << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}