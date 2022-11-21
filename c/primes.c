#include <stdio.h>

void primes_step(int n, int m, int res[], int max) {
    if (m < max) {
        int i = 0;
        while (n % res[i++] != 0 && i < m) {}
        if (i < m) {
            primes_step(n + 2, m, res, max);
        } else {
            res[m] = n;
            primes_step(n + 2, m + 1, res, max);
        }
    }
}

void primes(int res[], int max) {
    res[0] = 2;
    primes_step(3, 1, res, max);
}

int main() {
    int max = 20;
    int res[max];
    primes(res, max);

    for(int i = 0; i < max; i++) {
        printf("%d ", res[i]); // 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71
    }
    return 0;
}