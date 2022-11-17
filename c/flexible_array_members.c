#include <stdio.h>
#include <stdlib.h>

// flexible array members (FAM) sample 
// see more details here: https://www.scaler.com/topics/c/dynamic-array-in-c/ 
typedef struct vector {
    int cap;
    int size;
    int arr[];
} vector;

vector* create_vector(int cap) {
    vector* r = malloc(sizeof(vector*) + cap * sizeof(int));
    r->size = 0;
    r->cap = cap;
    return r;
}

vector* push(vector* v, int item) {
    if (v->size == v->cap) {
        int cap = 2 * v->cap;
        int size = v->size;
        v = realloc(v, sizeof(vector*) + cap * sizeof(int));
        v->cap = cap;
        v->size = size;
    }
    v->arr[v->size++] = item;
    return v;
}

int main() {
    vector* v = create_vector(5);
    int max = 3 * v->cap;

    for (int i = 0; i < max; i++) {
        v = push(v, i);
    }

    for (int i = 0; i < max; i++) {
        printf("%d ", v->arr[i]);
    }

    printf("\nCap:%d", v->cap);
    printf("\nSize:%d", v->size);

    free(v);
    return 0;
}