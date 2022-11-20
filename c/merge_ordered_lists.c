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

// copy range source[from, to) to target[0, (from - to))
int copy(int source[], int target[], int from, int to) {
    for (int i = 0; i < to - from; i++) {
        target[i] = source[from + i];
    }

    return to - from;
}

// sort target[n] array with merge sort
void merge_sort(int target[], int n) {
    int m = n / 2;
    if (m > 0) {
        int a[m];
        int b[n - m];

        copy(target, a, 0, m);
        copy(target, b, m, n);

        merge_sort(a, m);
        merge_sort(b, n - m);

        merge(a, m, b, n - m, target);
    }
}

void test_merge() {
    int a[] = {21, 28, 35, 40, 61, 75};
    int b[] = {16, 25, 47, 54};
    int c[10];

    printf("test merge...\n");
    int r = merge(a, 6, b, 4, c);

    for (int i = 0; i < r; i++) {
        printf("%d ", c[i]);
    }
}

void test_merge_sort() {
    int target[] = {21, 28, 35, 40, 61, 75, 16, 25, 47, 54};
    int n = 10;

    printf("test merge sort...\n");
    merge_sort(target, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    // 16 21 25 28 35 40 47 54 61 75
}

int main() {
    // test_merge();
    test_merge_sort();
    return 0;
}
