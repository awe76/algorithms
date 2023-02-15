#include <iostream>
#include <string>

int main() {
    char a[] = "hello";
    char b[] = "world";
    char c[strlen(a) + strlen(b) + 1];

    strcpy(c, a);
    char *r = strcat(c, b);

    std::cout << c << std::endl;
    std::cout << r << std::endl;
    return 0;
}