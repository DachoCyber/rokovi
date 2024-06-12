#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* right, *left;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void appendChild(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        appendChild(&(*root)->left, data);
    } else if (data > (*root)->data) {
        appendChild(&(*root)->right, data);
    }
}

int thereIsNodeV(Node* root, int v, int* found) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == v) {
        *found = 1;
        return (root->data % 2 == 0) ? root->data : 0;
    }
    int sum = 0;
    if (root->data % 2 == 0) {
        sum += root->data;
    }
    if (v < root->data) {
        return sum + thereIsNodeV(root->left, v, found);
    } else {
        return sum + thereIsNodeV(root->right, v, found);
    }
}

int addAllEvenVal(Node* root, int v) {
    int found = 0;
    int sum = thereIsNodeV(root, v, &found);
    if (found == 1) {
        return sum;
    }
    return -1;
}

int main() {
    int v = 4;
    Node* root = NULL;
    appendChild(&root, 1);
    appendChild(&root, 2);
    appendChild(&root, 4);

    printf("%d\n", addAllEvenVal(root, v));

    // Free the allocated memory (not shown for brevity)

    return 0;
}

