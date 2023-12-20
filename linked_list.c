/*
Linked list implementation:

Use a typedef struct to represent a node

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    Node *next;
} Node;


Node *initNode(int key) {
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    return node;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->key);
        temp = temp->next;
    }
}

int searchList(Node *head, int key) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->key == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    return 0;
}