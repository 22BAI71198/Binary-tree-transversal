#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int data;
   struct Node* left;
   struct Node* right;
} Node;

// Function to create a new node in heap
Node* NewNode(int data) {
   Node* node = (Node*)malloc(sizeof(Node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return node;
}

// Function to insert a new node in binary search tree
Node* InsertNode(Node* root, int data) {
   if (root == NULL) {
       return NewNode(data);
   }
   if (data < root->data) {
       root->left = InsertNode(root->left, data);
   } else if (data > root->data) {
       root->right = InsertNode(root->right, data);
   }
   return root;
}

// Function to perform Inorder Traversal
void InorderTraversal(Node* root) {
   if (root == NULL) {
       return;
   }
   InorderTraversal(root->left);
   printf("%d ", root->data);
   InorderTraversal(root->right);
}

// Function to perform Preorder Traversal
void PreorderTraversal(Node* root) {
   if (root == NULL) {
       return;
   }
   printf("%d ", root->data);
   PreorderTraversal(root->left);
   PreorderTraversal(root->right);
}

// Function to perform Postorder Traversal
void PostorderTraversal(Node* root) {
   if (root == NULL) {
       return;
   }
   PostorderTraversal(root->left);
   PostorderTraversal(root->right);
   printf("%d ", root->data);
}

int main() {
   Node* root = NULL;
   int data, choice;
   while (1) {
       printf("\n1. Insert Node");
       printf("\n2. Inorder Traversal");
       printf("\n3. Preorder Traversal");
       printf("\n4. Postorder Traversal");
       printf("\n5. Exit");
       printf("\nEnter your choice: ");
       scanf("%d", &choice);
       switch (choice) {
           case 1:
               printf("\nEnter the data to be inserted: ");
               scanf("%d", &data);
               root = InsertNode(root, data);
               break;
           case 2:
               InorderTraversal(root);
               break;
           case 3:
               PreorderTraversal(root);
               break;
           case 4:
               PostorderTraversal(root);
               break;
           case 5:
               exit(0);
           default:
               printf("\nInvalid choice");
       }
   }
   return 0;
}
