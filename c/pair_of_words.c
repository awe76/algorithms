#include <stdio.h>
#include <string.h>

typedef struct match {
    int from1;
    int from2;
    int count;
} match;

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
} 

void set_result(char s1[], char s2[], int l1, int l2, match m, char res[]) {
    int k = -1;
    if (m.count == 0) {
        for (int i = 0; i < l1; i++) {
            res[++k] = s1[i];
        }

        for (int i = 0; i < l2; i++) {
            res[++k] = s2[i];
        }

        return;
    }

    if (m.count == l1) {
        for (int i = 0; i < l2; i++) {
            res[++k] = s2[i];
        }

        return;
    }

    if (m.from2 == 0) {
        for (int i = 0; i < l1 - m.count; i++) {
            res[++k] = s1[i];
        }

        for (int i = m.from2; i < l2; i++) {
            res[++k] = s2[i];
        }

        return;
    }

    if (m.from1 == 0) {
        for (int i = 0; i < l2 - m.count; i++) {
            res[++k] = s2[i];
        }

        for (int i = m.from1; i < l1; i++) {
            res[++k] = s1[i];
        }

        return;
    } 
}

int main() {
    char* s1 = "1101";
    char* s2 = "0110111001";
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    
    int res = is_match(s1, s2, 0, 1, 4);
    printf("%d\n", res);

    match m = find_match(s1, s2, l1, l2);
    printf("%d:[%d, %d]\n", m.count, m.from1, m.from2);

    s1 = "1101";
    s2 = "0111111111";

    m = find_match(s1, s2, l1, l2);
    printf("%d:[%d, %d]\n", m.count, m.from1, m.from2);

    int ln = get_result_len(s1, s2, l1, l2, m);
    printf("%d\n", ln);
    char r[ln + 1];
    r[ln] = '\0';

    set_result(s1, s2, l1, l2, m, r);
    printf("%s\n", r); // 110111111111

    s1 = "1101";
    s2 = "1101";

    m = find_match(s1, s2, l1, l2);
    printf("%d:[%d, %d]\n", m.count, m.from1, m.from2);
}

