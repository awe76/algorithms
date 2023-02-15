#include <iostream>

int main() {
    int currVal = 0, val = 0;
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal) {
                cnt++;
            } else {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                cnt = 1;
                currVal = val;
            }
        }
        std::cout << std::endl << currVal << " occurs " << cnt << " times" << std::endl;
    }

    return 0;
}