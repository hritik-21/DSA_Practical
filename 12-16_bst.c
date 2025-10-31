// Write a program to perform following operations on BST (Any two)
// 1. Insert a node
// 2. Delete a node
// 3. preorder traversal
// 4. inorder traversal
// 5. postorder traversal

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int value){
    if(root==NULL){
        return createNode(value);
    }

    if(value < root->data){
        root->left = insertNode(root->left, value);
    }
    else if(value > root->data){
        root->right = insertNode(root->right, value);
    }
    return root;
}

struct Node* findMin(struct Node* node){
    while(node && node->left != NULL){
        node = node->left;
    }
    return node;
}

struct Node* deleteNode(struct Node* root, int key){
    if(root==NULL){
        return root;
    }

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void preorder(struct Node* root){
    if(root == NULL) return;    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    struct Node* root = NULL;
    int choice, value;

    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 30);

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}