#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct match {
    int from1;
    int from2;
    int count;
} match;

typedef struct range {
    char* str; 
    int from;
    int to;
} range;

// detect if s1 = [from1, from1+count) matches s2 = [from2, from2 + count)
int is_match(char s1[], char s2[], int from1, int from2, int count) {
    for (int i = 0; i < count; i++) {
        if (s1[from1 + i] != s2[from2 + i]) {
            return 0;
        }
    }

    return 1;
}

// find maximum matching of two strings
match find_match(char s1[], char s2[], int l1, int l2) {
    match r = {.count = 0};
    int count = 1;
    while (count < l1) {
        if (is_match(s1, s2, l1 - count, 0, count) == 1) {
            r.count = count;
            r.from1 = l1 - count;
            r.from2 = 0;
        };

        if (is_match(s1, s2, 0, l2 - count, count) == 1) {
            if (count > r.count) {
                r.count = count;
                r.from1 = 0;
                r.from2 = l2 - count;
            }
        };

        count++;
    }

    int to = l2 - l1;
    int from = 0;
    while (is_match(s1, s2, 0, from, l1) == 0 && from <= to) {
        from++;
    }

    if (from <= to) {
        r.count = l1;
        r.from1 = 0;
        r.from2 = from;
    }

    return r;
}

int get_result_len(char s1[], char s2[], int l1, int l2, match m) {
    if (m.count == 0) {
        return l1 + l2;
    }

    if (m.count == l1) {
        return l2;
    }

    if (m.from2 == 0) {
        return l1 - m.count + l2;
    }

    if (m.from1 == 0) {
        return l2 - m.count + l1;
    }

    return -1;
} 

void set_result(char s1[], char s2[], int l1, int l2, match m, char res[]) {
    range r1 = {.str = s1, .from = 0, .to = l1};
    range r2 = {.str = s2, .from = 0, .to = l2};

    if (m.count == l1) {
        res = s2;
    }

    if (m.count != 0) {
        if (m.from2 == 0) {
            r1.to = l1 - m.count;
        }

        if (m.from1 == 0) {
            r1.str = s2;
            r2.str = s1;
            r1.to = l2 - m.count;
            r2.to = l1;
        }
    }

    int k = -1;
    for (int i = r1.from; i < r1.to; i++) {
        res[++k] = r1.str[i];
    }

    for (int i = r2.from; i < r2.to; i++) {
        res[++k] = r2.str[i];
    }
}

void test_is_match() {
    char* s1 = "1101";
    char* s2 = "0110111001";

    int res = is_match(s1, s2, 0, 1, 4);
    assert(res == 1);
}

void test_find_match() {
    char* s1 = "1101";
    char* s2 = "0110111001";

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    match m = find_match(s1, s2, l1, l2);
    assert(m.count == 4);
    assert(m.from1 == 0);
    assert(m.from2 == 1);
}

void test_find_match_self() {
    char* s1 = "1101";
    char* s2 = "1101";

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    match m = find_match(s1, s2, l1, l2);
    assert(m.count == 4);
    assert(m.from1 == 0);
    assert(m.from2 == 0);
}

void test_set_result() {
    char* s1 = "1101";
    char* s2 = "0111111111";

    int l1 = strlen(s1);
    int l2 = strlen(s2);
    match m = find_match(s1, s2, l1, l2);

    int len = get_result_len(s1, s2, l1, l2, m);
    char res[len + 1];
    res[len] = '\0';

    set_result(s1, s2, l1, l2, m, res);
    assert(strcmp(res, "110111111111") == 0);
}

int main() {
    test_is_match();
    test_find_match();
    test_find_match_self();
    test_set_result();

    int l1;
    printf("Enter first string's length:\n");
    scanf("%d", &l1);

    char s1[l1];
    printf("Enter first string:\n");
    scanf("%s", s1);

    int l2;
    printf("Enter second string's length:\n");
    scanf("%d", &l2);

    char s2[l2];
    printf("Enter second string:\n");
    scanf("%s", s2);

    match m = find_match(s1, s2, l1, l2);

    int len = get_result_len(s1, s2, l1, l2, m);
    char res[len + 1];
    res[len] = '\0';

    set_result(s1, s2, l1, l2, m, res);

    printf("Result is:\n");
    printf("%s\n", res);

    return 0;
}

