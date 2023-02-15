#include <iostream>
#include <string>
using std::string;

int main() {
    string prev;
    string word;
    while (std::cin >> word) {
        if (prev == word) {
            std::cout << '<' << word << "> is a duplicate" << std::endl;
            break;
        }

        prev = word;
    }

    return 0;
}