// NAME:Vaishnavi Kumari
// SAP ID: 590029048


// Problem Statement 1:
// Write a C program to create a binary tree dynamically using a linked list representation. The program should allow the user to insert nodes into the tree in level-order (breadth-first manner).

// Requirements:
// 1. Define a structure for a tree node.
// 2. Dynamically allocate memory for each node.
// 3. Insert elements level-wise.
// 4. Display the tree using level-order traversal.

// REQUIRED CODE:

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    // Simple queue using array
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        // Check left
        if (temp->left == NULL) {
            temp->left = createNode(data);
            break;
        } else {
            queue[rear++] = temp->left;
        }

        // Check right
        if (temp->right == NULL) {
            temp->right = createNode(data);
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}


void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left)
            queue[rear++] = temp->left;

        if (temp->right)
            queue[rear++] = temp->right;
    }
}


int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}


// Problem Statement 2:
// Write a C program to create a binary tree and perform recursive traversal operations including:
// 1. Inorder Traversal
// 2. Preorder Traversal
// 3. Postorder Traversal

// Requirements:
// 1. Use recursive functions.
// 2. Accept user input to build the tree.
// 3. Display all three traversal outputs.


// REQUIRED CODE:
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* createTree() {
    int value;
    printf("Enter value (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    struct Node* root = createNode(value);

    printf("Enter left child of %d\n", value);
    root->left = createTree();

    printf("Enter right child of %d\n", value);
    root->right = createTree();

    return root;
}


void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


int main() {
    struct Node* root;

    printf("Create Binary Tree:\n");
    root = createTree();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
