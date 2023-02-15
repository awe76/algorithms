#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int num;
    vector<int> res;
    while(cin >> num) {
        res.push_back(num);
        cout << res.size() << endl;
    }

    return 0;
}