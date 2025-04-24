#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}


struct Node* constructTreeFromInorderPreorder(int inorder[], int preorder[], int inorderStart, int inorderEnd, int* preorderIndex) {
    if (inorderStart > inorderEnd)
        return NULL;

    
    int rootValue = preorder[*preorderIndex];
    (*preorderIndex)++; 
    struct Node* root = createNode(rootValue);

    if (inorderStart == inorderEnd)
        return root;

    int rootIndex = search(inorder, inorderStart, inorderEnd, rootValue);


    root->left = constructTreeFromInorderPreorder(inorder, preorder, inorderStart, rootIndex - 1, preorderIndex);
    root->right = constructTreeFromInorderPreorder(inorder, preorder, rootIndex + 1, inorderEnd, preorderIndex);

    return root;
}


void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    int preorderIndex = 0;

 
    struct Node* root = constructTreeFromInorderPreorder(inorder, preorder, 0, n - 1, &preorderIndex);


    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
