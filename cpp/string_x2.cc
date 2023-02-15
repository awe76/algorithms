#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string input;
    cin >> input;
    for (decltype(input.size()) i = 0; i < input.size(); ++i) 
        input[i] = 'X';

    cout << input << endl;
    return 0;
}