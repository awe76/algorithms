#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* duplicate(char source[]) {
    int len = strlen(source);
    char* res = malloc(len + 1);
    strcpy(res, source);
    return res;
}

void test_duplicate() {
    char* s = "abcde";
    char* dup = duplicate(s);

    assert(strcmp(dup, s) == 0);
    printf("%s\n", dup);
    free(dup);
}

int* create_array(int n, int initial_value) {
    int* res = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = initial_value;
    }

    return res;
}

void test_create_array() {
    int* res = create_array(5, 7);
    for (int i = 0; i < 5; i++) {
        printf("%d", res[i]);
    }
    free(res);
}

typedef struct point {
    int x, y;
} point;

typedef struct rectangle {
    point upper_left, lower_right;
} rectangle;

rectangle* create_rectangle() {
    rectangle* res = malloc(sizeof(rectangle));
    res->upper_left.x = 10;
    res->upper_left.y = 25;

    res->lower_right.x = 20;
    res->lower_right.y = 40;

    return res;
}

void test_create_rectangle() {
    rectangle* rec = create_rectangle();

    printf("\n[%d, %d] - [%d, %d]", rec->upper_left.x, rec->upper_left.y, rec->lower_right.x, rec->lower_right.y);
    free(rec);
}


int main() {
    test_duplicate();
    test_create_array();
    test_create_rectangle();

    return 0;
}