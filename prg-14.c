// 14. Write a program to create binary search tree with the elements {2,5,1,3,9,0,6} and perform
// inorder, preorder and post order traversal.
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

																																													// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
	return createNode(data);
    }

    if (data < root->data) {
	root->left = insert(root->left, data);
    } else if (data > root->data) {
	root->right = insert(root->right, data);
    }

    return root;
}

 
void inorder(struct Node* root) {
    if (root != NULL) {
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
    }
}

 
void preorder(struct Node* root) {
    if (root != NULL) {
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
    }
}

 
void postorder(struct Node* root) {
    if (root != NULL) {
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
    }
}

 
int main() {
    struct Node* root = NULL;

    
    int elements[] = {2, 5, 1, 3, 9, 0, 6};
     int i;
    for ( i = 0; i < sizeof(elements)/sizeof(elements[0]); i++) {
        root = insert(root, elements[i]);
    }

    
    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}