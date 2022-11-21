#include <stdio.h>

// calculate exponent with max precision
double t_exp(int max) {
    int fact = 2;
    double res = 2;
    for (int n = 2; n <= max; n++, fact *= n) {
        res += 1.0 / fact;
    }

    return res;
}

int main() {
    for (int n = 2; n < 10; n++) {
        double res = t_exp(n);
        printf("%lf\n", res);
    }
    return 0;
}