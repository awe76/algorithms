#include <iostream>
using std::begin;
using std::end;

int main() {
    int ia[3][4] = {
        {1, 4, 6, 7},
        {4, 7, 9, 0},
        {7, 5, 7, 8}
    };

    for (auto row = begin(ia); row != end(ia); ++row) {
        for (auto item = begin(*row); item != end(*row); ++item) {
            std::cout << *item << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}