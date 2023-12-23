#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    void *left;
    void *right;
} Node;

Node *root = NULL;

// init
Node *initNode(int data) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocaiton failed.\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// insert
int insertNode(int data) {
    Node *node = initNode(data);

    if (root == NULL) {
        root = node;
    } else {
        
    }
}



// remove

// search
int findNode(int data) {
    Node *curr = root;

    while (curr != NULL) {
        if (curr->data == data) {
            return 1;
        } else {
            if (curr->data > data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
    return 0;
}


void printMenu() {
    printf("You can perform the following operations:\n");
    printf("\t1. Add a node to the tree\n");
    printf("\t2. Remove a node to the tree\n");
    printf("\t3. Search for a given node\n");
    printf("\t4. Quit\n");
}


int main() {


    int operation = -1;
    int num_received;

    while (operation != 4) {
        printMenu();
        num_received = scanf("%d", &operation);
        if (num_received == 1 && operation > 0 && operation <= 4) {
            switch (operation) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    // Quit
                    break;
            }
        }
    }

    return 0;
}