#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void kthSmallestUtil(struct Node* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k)
        return;

    kthSmallestUtil(root->left, k, count, result);

    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    kthSmallestUtil(root->right, k, count, result);
}

int kthSmallest(struct Node* root, int k) {
    int count = 0;
    int result = -1;
    kthSmallestUtil(root, k, &count, &result);
    return result;
}

int main() {
    
    struct Node* root = NULL;
    root = insert(root, 5);
    insert(root, 45);
    insert(root, 99);
    insert(root, 87);
    insert(root, 54);
    insert(root, 23);

    int k = 3;
    int result = kthSmallest(root, k);
    if (result != -1)
        printf("The %dth smallest element is %d\n", k, result);
    else
        printf("Less than %d elements in the BST.\n", k);

    return 0;
}
