#include <stdio.h>

// merge two ordered lists a[n] and b[m] into the c list
int merge(int a[], int n, int b[], int m, int c[]) {
    int i = 0;
    int j = 0;
    int k = -1;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[++k] = a[i++];
        } else {
            c[++k] = b[j++];
        }
    }

    while (i < n) {
        c[++k] = a[i++];
    }

    while (j < m) {
        c[++k] = b[j++];
    }

    return m + n;
}

int main() {
    int a[] = {21, 28, 35, 40, 61, 75};
    int b[] = {16, 25, 47, 54};
    int c[10];

    int r = merge(a, 6, b, 4, c);
    for (int i = 0; i < r; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}
