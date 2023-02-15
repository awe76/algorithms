#include <iostream>

int comp(int a[], int b[], unsigned len) {
    for (unsigned i = 0; i < len; ++i) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }

    return 0;
}

int main() {
    int a[] = {1, 5, 6, 7, 9};
    int b[] = {1, 5, 6, 0, 9};

    int res = comp(a, b, std::end(a) - std::begin(a));

    std::cout << res << std::endl;
    return 0;
}

