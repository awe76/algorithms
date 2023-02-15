#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> res = {1, 2, 6};
    for (auto it = res.begin(); it != res.end(); ++it)
        cout << *it << endl;

    return 0;
}