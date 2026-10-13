#include <stdio.h>

#include <stdlib.h>

struct Node {

     int data;

     struct Node* left;

     struct Node* right;

};

struct Node* createNode(int val) {

     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

     newNode->data = val;

     newNode->left = NULL;

     newNode->right = NULL;

     return newNode;

}

// Inorder: Left -> Root -> Right

void inorder(struct Node* root) {

     if (root == NULL)

       return;

     inorder(root->left);

     printf("%d ", root->data);

     inorder(root->right);

}

// Preorder: Root -> Left -> Right

void preorder(struct Node* root) {

     if (root == NULL)

         return;

    printf("%d ", root->data);

    preorder(root->left);

    preorder(root->right);

}

// Postorder: Left -> Right -> Root

void postorder(struct Node* root) {

    if (root == NULL)

         return;

    postorder(root->left);

    postorder(root->right);

    printf("%d ", root->data);

}

int main() {

    /*

    * Binary Tree Structure:

    *

    *          1

    *         /\

    *        2 3

    *        /\/\

    *       4 56 7

    */

    struct Node* root = createNode(1);

    root->left       = createNode(2);

    root->right       = createNode(3);

  root->left->left = createNode(4);

  root->left->right = createNode(5);

  root->right->left = createNode(6);

  root->right->right = createNode(7);

  printf("Binary Tree Structure:\n");

  printf("       1\n");

  printf("       / \\\n");
  printf("      2 3\n");
  printf("      / \\ / \\\n");
  printf("    4 5 6 7\n\n");
  printf("Inorder Traversal (Left -> Root -> Right): ");
  inorder(root);
  printf("\n");
  printf("Preorder Traversal (Root -> Left -> Right): ");
  preorder(root);
  printf("\n");
  printf("Postorder Traversal (Left -> Right -> Root): ");
  postorder(root);
  printf("\n");
  return 0;
}
