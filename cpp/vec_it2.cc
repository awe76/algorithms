#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> res;
    for (unsigned val = 1; val < 11; ++val)
        res.push_back(val);

    for (auto it = res.begin(); it != res.end(); ++it) 
        *it *= 2;

    for (auto it = res.begin(); it != res.end(); ++it)
        cout << *it << endl;

    return 0;
}