#include <stdio.h>

// Linked list represented as an array reversion
int reverse(int list[]) {
    int prev = -1;
    int current = 0;
    int next = 0;
    while (current != -1) {
        next = list[current];
        list[current] = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() {
    /* 0->2->6->3->4->1->5->-1
       0  1  2  3  4  5  6 
       2  5  6  4  1 -1  3 */
    int list[7] = {2, 5, 6, 4, 1, -1, 3};
    int head = reverse(list);

    printf("Result:\n");

    for (int i = 0; i < 7; i++) {
        printf("%d ", list[i]);
    }

    printf("\nHead:\n");
    printf("%d", head); // head: 5
    /* 5->1->4->3->6->2->0->-1
       0  1  2  3  4  5* 6 
      -1  4  0  6  3  1  2 */
    return 0;
}

