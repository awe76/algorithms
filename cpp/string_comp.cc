#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string first, second;
    getline(cin, first);
    getline(cin, second);

    cout << (first + " " + second) << endl;
    return 0;
}