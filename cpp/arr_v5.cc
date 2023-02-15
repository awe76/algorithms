#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> src = {1, 3, 6, 6};
    int *dest = src.data();

    for (int i = 0; i < 4; i++) 
        std::cout << *(dest + i) << std::endl;

    return 0;
}
