#include <stdio.h>
#include <string.h>

int is_palindrome_without_spaces(char str[], int from, int to) {
    for (int l = from, r = to; l < r; l++, r--) {
        if (str[l] != str[r]) {
            return 0;
        }
    }

    return 1;
}

int is_palindrome(char str[], int from, int to) {
    int l = from;
    int r = to;
    int found = 0;
    while (l < r) {
        if (str[l] == ' ') {
            l++;
            continue;
        }

        if (str[r] == ' ') {
            r--;
            continue;
        }

        if (str[l] == str[r]) {
            found = 1;
        } else {
            return 0;
        }

        l++;
        r--;
    }

    return found;
}

typedef struct range {
    int from;
    int to;
} range;

range find_palindrome(char str[]) {
    int len = strlen(str);
    range res = {.from = -1, .to = -1};

    for (int from = 0; from < len - 1; from++) {
        for (int to = from + 1; to < len; to++) {
            if (str[from] != ' ' && is_palindrome(str, from, to) == 1) {
                res.from = from;
                res.to = to;
                return res;
            }
        }
    }

    return res;
}

int main() {
    char* str = "abccba";

    int res = is_palindrome(str, 0, 5);
    
    printf("%s: %d\n", str, res);

    str = "abcba";
    res = is_palindrome(str, 0, 4);
    
    printf("%s: %d\n", str, res);

    str = "nurses run";
    res = is_palindrome(str, 0, 9);
    printf("%s: %d\n", str, res);

    range g = find_palindrome(str);
    printf("[%d, %d]\n", g.from, g.to);

    str = "who am I";
    g = find_palindrome(str);
    printf("[%d, %d]\n", g.from, g.to);

    str = "who nurses run am I";
    g = find_palindrome(str);
    printf("[%d, %d]\n", g.from, g.to);

    return 0;
}