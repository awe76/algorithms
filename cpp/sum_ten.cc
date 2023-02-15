#include <iostream>

int main() {
    int num = 1, sum = 0;

    // keep executing the while as long as num is less to 11 
    while (num < 11) {
        sum += num; // assign sum + val to sum
        num++; // add 1 to num
    }

    std::cout << "The sum of numbers from 1 to 10 is " << sum << std::endl;
    return 0;
}