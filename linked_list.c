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

// initializes a node
Node *initNode(int key) {
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    return node;
}

// prints a linked-list
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->key);
        temp = temp->next;
    }
}

// searches a linked-list
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

// prints the operations menu
void printMenu() {
    printf("You can perform the following operations:\n");
    printf("\t1. Add a node to the list\n");
    printf("\t2. Remove a node from the list \n");
    printf("\t3. Insert a node to the list at specified index");
    printf("\t4. Print the list\n");
    printf("\t5. Search the list\n");
    printf("\t6. Quit.\n");
}

int main(int argc, char **argv) {

    int operations = -1;
    int num;

    return 0;
}