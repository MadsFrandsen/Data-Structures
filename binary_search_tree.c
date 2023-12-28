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
        if (parent->data > data) {
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

                if (parent == NULL) {
                    root = NULL;
                } else if (parent->left == curr) {
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
                temp = curr->right;
                curr->right = temp->right;
                curr->left = temp->left;
                curr->data = temp->data;
                free(temp);
            }

            // successfully removed the node
            printf("Node was successfully removed.\n");
            return 1;

        } else if (curr->data > data) {
            parent = curr;
            curr = curr->left;
        } else {
            parent = curr;
            curr = curr->right;
        }
    }
    // node not in tree
    printf("Node could not be found in tree.\n");
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
        printf("%d ",node->data);
        inorderPrint(node->right);
    }
}

void printMenu() {
    printf("You can perform the following operations:\n");
    printf("\t1. Add a node to the tree\n");
    printf("\t2. Remove a node to the tree\n");
    printf("\t3. Search for a given node\n");
    printf("\t4. Print the tree inorder.\n");
    printf("\t5. Quit\n");
}


int main() {

    int operation = -1;
    int val;
    int num_received;

    while (operation != 5) {
        printMenu();
        num_received = scanf("%d", &operation);
        if (num_received == 1 && operation > 0 && operation <= 4) {
            switch (operation) {
                case 1:
                    printf("Please give a value for the node.\n");
                    num_received = scanf("%d", &val);
                    if (num_received == 1) {
                        insertNode(val);
                    } else {
                        printf("Invalid input. Please specify an integer.\n");
                        while (getchar() != '\n');
                    }
                    break;
                case 2:
                    printf("Please specify value of node to be removed.\n");
                    num_received = scanf("%d", &val);
                    if (num_received == 1) {
                        removeNode(val);
                    } else {
                        printf("Invalid input. Please specify an integer.\n");
                        while (getchar() != '\n');
                    }
                    break;
                case 3:
                    printf("Please specify value to be searched for.\n");
                    num_received = scanf("%d", &val);
                    if (num_received == 1) {
                        findNode(val);
                    } else {
                        printf("Invalid input. Please specify an integer.\n");
                        while (getchar() != '\n');
                    }
                    break;
                case 4:
                    inorderPrint(root);
                    printf("\n");
                    break;
                case 5:
                    // Quit
                    break;
            }
        }
    }

    return 0;
}