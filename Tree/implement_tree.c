#include <stdio.h>
#include <stdlib.h>

// Creating the structure of the tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *node;

/* Function to create the tree */
node create_tree() {
    int x;
    printf("Enter data (Enter -1 for no node): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    }

    node n = (node) malloc(sizeof(struct node)); // Correct malloc usage
    if (n == NULL) {
        printf("Memory allocation failed !!\n");
        return NULL;
    }

    n->data = x;
    printf("Enter left child of %d: ", x);
    n->left = create_tree(); // Recursively create left subtree
    printf("Enter right child of %d: ", x);
    n->right = create_tree(); // Recursively create right subtree

    return n;
}
// Creating the inorder traversal function (left -> root -> right)
void inorder(node n){
    if(n == NULL){
        return;
    }
    inorder(n -> left);
    printf("%d ",n->data);
    inorder(n -> right);
}
// creating the preorder traversal function (root -> left -> right)
void preorder(node n){
    if(n == NULL){
        return;
    }
    printf("%d ", n -> data);
    preorder(n -> left);
    preorder(n -> right);
}
// creating the postorder traversal function (left -> right -> root)
void postorder(node n){
    if(n == NULL){
        return;
    }
    postorder(n -> left);
    postorder(n -> right);
    printf("%d ", n -> data);
}
/* Main function */
int main(void) {
    node root = NULL;
    root = create_tree();
    printf("INORDER TRAVERSAL -> ");
    inorder(root);
    printf("\n");
    printf("PREORDER TRAVERSAL -> ");
    preorder(root);
    printf("\n");
    printf("POSTORDER TRAVERSAL -> ");
    postorder(root);
    printf("\n");
    return 0;
}
