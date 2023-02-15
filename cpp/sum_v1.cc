#include <iostream>

int sum(std::initializer_list<int> items) {
    int res = 0;
    for (const auto &n: items) 
        res += n;

    return res;
}

int main() {
    int r = sum({1, 4, 5});
    std::cout << r << std::endl;
    return 0;
}