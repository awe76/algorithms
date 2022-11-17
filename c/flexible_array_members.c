#include <stdio.h>
#include <stdlib.h>

// flexible array members (FAM) sample 
// see more details here: https://www.scaler.com/topics/c/dynamic-array-in-c/ 
typedef struct vector {
    int size;
    int arr[];
} vector;

vector* create_vector(int size) {
    vector* r = malloc(sizeof(vector*) + size * sizeof(int));
    r->size = size;
    return r;
}

int main() {
    vector* v = create_vector(5);

    for (int i = 0; i < v->size; i++) {
        v->arr[i] = i;
    }

    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->arr[i]);
    }

    printf("\nSize:");
    printf("\n%d", v->size);

    free(v);
    return 0;
}