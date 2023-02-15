#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement {
    struct ListElement *next;
    int data;
} ListElement;

ListElement* find(ListElement *head, int data) {
    ListElement* current = head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    return current;
}

void forEach(ListElement *current, void (*f)(ListElement*)) {
    while(current != NULL) {
        f(current);
        current = current->next;
    }
}

void printElement(ListElement* item) {
    printf("%d\n", item->data);
}

int insertElement(ListElement** current, int data) {
    ListElement *item = malloc(sizeof(ListElement));

    if (item == NULL) {
        return 0;
    }

    item->data = data;
    item->next = *current;

    *current = item;
    return 1;
}

int deleteElement(ListElement **current, ListElement *target) {
    while(*current) {
        if (*current == target) {
            // current points to the header pointer or to the next pointer whithin preceding element
            *current = target->next;
            free(target);
            return 1;
        }
        current = &((*current)->next);
    }

    return 0;
}

void push(ListElement **head, int data) {

}

void deleteList(ListElement **head) {
    ListElement* target = *head;
    while(target != NULL) {
        // deleteElement(&target, target);
        ListElement* next = target->next;
        free(target);
        target = next;
    }

    *head = NULL;
}

int main() {
    ListElement* head = NULL;
    insertElement(&head, 1);
    insertElement(&head, 2);
    insertElement(&head, 3);

    forEach(head, printElement);
}
