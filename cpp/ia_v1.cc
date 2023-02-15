#include <iostream>

int main() {
    int ia[3][4] = {
        {1, 4, 6, 7},
        {4, 7, 9, 0},
        {7, 5, 7, 8}
    };

    for (const auto &row: ia) {
        for (const auto item: row) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    };

    return 0;
}