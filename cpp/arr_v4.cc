#include <iostream>
#include <vector>

using std::vector;

int main() {
    int src[] = {1, 3, 6, 6};
    vector<int> dest(std::begin(src), std::end(src));

    src[0] = 2;

    for(auto val: dest) 
        std::cout << val << std::endl;

    return 0;
}
