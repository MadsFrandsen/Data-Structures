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
        Node *curr = root;
        Node *parent;
        while (curr != NULL) {
            parent = curr;

            if (curr->data > data) {
                curr = curr->left;
            } else if (curr->data < data) {
                curr = curr->right;
            } else {
                printf("Node already exists in the tree.\n");
                free(node);
                return 0;   
            }
        }
        if (curr->data > data) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }

    return 1;
}


// remove
int removeNode(int data) {
    Node *curr = root;
    Node *parent = NULL;
    Node *temp = NULL;

    while (curr != NULL) {
        if (curr->data == data) {

            if (curr->left == NULL && curr->right == NULL) {
                if (parent->left == curr) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                free(curr);
            } else if (curr->left != NULL && curr->right != NULL) {
                Node *p = NULL;
                temp = curr->right;

                // find successor
                while (temp->left != NULL) {
                    p = temp;
                    temp = temp->left;
                }

                if (p != NULL) {
                    p->left = temp->right;
                } else {
                    curr->right = temp->right;
                }

                curr->data = temp->data;
                free(temp);
            } else {
                if (curr->left == NULL) {
                    temp = curr->right;
                    curr->right = NULL;
                } else {
                    temp = curr->left;
                    curr->left = NULL;
                }
                curr->data = temp->data;
                free(temp);
            }

            return 1;

        } else if (curr->data > data) {
            parent = curr;
            curr = curr->left;
        } else {
            parent = curr;
            curr = curr->right;
        }
    }
    return 0;
}


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

// print tree inorder
void inorderPrint(Node *node) {
    if (node != NULL) {
        inorderPrint(node->left);
        print(node->data);
        inorderPrint(node->right);
    }
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