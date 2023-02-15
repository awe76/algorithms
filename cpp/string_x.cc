#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string input;
    cin >> input;
    for (char &c: input) 
        c = 'X';

    cout << input << endl;
    return 0;
}