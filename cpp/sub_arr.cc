#include <iostream>
#include <vector>
using std::vector;

int main() {
    vector<int> a = {1, 3, 4, 6, 7};
    vector<int> b = {9};

    int i = 0;
    bool found = false;
    while (i < a.size() - b.size() + 1) {
        int j = 0;
        while(a[i + j] == b[j] && j < b.size()) 
            ++j;

        if (j == b.size()) {
            found = true;
            break;
        }
        ++i;
    }

    std::cout << found << ':' << i << std::endl;
}