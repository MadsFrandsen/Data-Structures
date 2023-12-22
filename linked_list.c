/*
Linked list implementation:

Use a typedef struct to represent a node

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    void *next;
} Node;

Node *head = NULL;


// initializes a node
Node *initNode(int key) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocaiton failed.\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->next = NULL;
    return node;
}

// adds a node at the front of the list
void addNodeFront(int key) {

    Node *node = initNode(key);

    if (head == NULL) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }
}

// adds a node at the end of the list
void addNodeEnd(int key) {
    Node *node = initNode(key);

    if (head == NULL) {
        head = node;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

// removes a node from the list
int removeNode(int key) {
    Node *prev = head;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->key == key) {
            if (temp == head) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            return 1;
        }
        prev = temp;
        temp = temp->next;
    }

    return 0;
}

// inserts a node at the given index
// bug in this code -- need fix
int insertNodeAtIndex(int idx, int key) {
    Node *temp = head;
    while (temp != NULL && idx != 0) {
        temp = temp->next;
        idx--;
    }
    if (idx != 0) {
        printf("Position is too far into list\n");
        return 0;
    } else {
        Node *node = initNode(key);
        node->next = temp->next;
        temp->next = node;
        return 1;
    }
}

// prints the linked-list
void printList() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

// searches the linked-list
int searchList(int key) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->key == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// frees the linked list
void freeList() {
    Node *curr = head;
    Node *temp = head;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}

// prints the operations menu
void printMenu() {
    printf("You can perform the following operations:\n");
    printf("\t1. Add a node to the front of the list\n");
    printf("\t2. Add a node at the end of the list\n");
    printf("\t3. Remove a node from the list \n");
    printf("\t4. Insert a node to the list at specified index\n");
    printf("\t5. Print the list\n");
    printf("\t6. Search the list\n");
    printf("\t7. Quit.\n");
}

int main(int argc, char **argv) {

    int operation = -1;
    int val;
    int val2;
    int num_received;

    while (operation != 7) {
        printMenu();
        num_received = scanf("%d", &operation);
        if (num_received == 1 && operation > 0 && operation <= 7) {
            switch (operation) {
                case 1:
                    printf("Please type an integer value for node.\n");
                    num_received = scanf("%d", &val);
                    if (num_received == 1) {
                        addNodeFront(val);
                    } else {
                        printf("Invalid input. Please specify an integer.\n");
                        while (getchar() != '\n');
                    }
                    break;
                case 2:
                    printf("Please type an integer value for node.\n");
                    num_received = scanf("%d", &val);
                    if (num_received == 1) {
                        addNodeEnd(val);
                    } else {
                        printf("Invalid input. Please specify an integer.\n");
                        while (getchar() != '\n');
                    }
                    break;
                case 3:
                    printf("Please specify node to remove.\n");
                    num_received = scanf("%d", &val);
                    if (num_received == 1) {
                        if (removeNode(val)) {
                            printf("Node removed successfully.\n");
                        } else {
                            printf("Could not find node.\n");
                        }
                    } else {
                        printf("Invalid input. Please specify an integer.\n");
                        while (getchar() != '\n');
                    }
                    break;
                case 4:
                    printf("Please type an integer value for the node and an index.\n");
                    num_received = scanf("%d", &val);
                    int index = scanf("%d", &val2);
                    if (num_received == 1 && index == 1) {
                        insertNodeAtIndex(val2, val);
                    } else {
                        printf("Invalid input. Please specify two integers.\n");
                        while (getchar() != '\n');
                    }
                    break;
                case 5:
                    printList();
                    break;
                case 6:
                    printf("Please give integer value to search for.\n");
                    num_received = scanf("%d", &val);
                    if (num_received == 1) {
                        int result =searchList(val);
                        if (result) {
                            printf("Found key in list.\n");
                        } else {
                            printf("Key does not exist in list.\n");
                        }
                    } else {
                        printf("Invalid input. Please specify an integer.\n");
                        while (getchar() != '\n');
                    }
                    break;
                case 7:
                    // Quit
                    break;
            }
        }
    }

    freeList();

    return 0;
}