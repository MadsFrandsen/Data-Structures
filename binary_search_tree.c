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



int main() {
    return 0;
}