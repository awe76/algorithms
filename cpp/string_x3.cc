#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    const string input("Keep out!");
    
    for (auto &c: input) 
        c = 'X';

    cout << input << endl;
    return 0;
}