// Creating the binary tree and performing the traversal (inorder traversal) | (preorder traversal) | (postorder traversal)

/* Declaring the important libraries */
#include<stdio.h>
#include<stdlib.h>

// Creating the structure !!
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}*node;

/* Construction the create_tree function */
node create_tree(){
    // Dynamic memory allocation
    node n = (node) malloc (sizeof(struct node));
    if(n == NULL){ // checking  if the memory allocation failed or not ?
        printf("Memory allocation failed !!\n");
        return NULL;
    }
    int x;
    printf("Enter the data (enter -1 for NULL): ");
    scanf("%d",&x);

    if(x == -1){
        return NULL;
    }

    n -> data = x;
    printf("Enter the left child of %d: ",x);
    n -> left = create_tree(); // Recursion method !
    printf("Enter the right child of %d: ",x);
    n -> right = create_tree(); // Recursion method !

    return n;
}

// creating the inorder traversal program !!
void inorder(node n){
    if(n == NULL){
        return;
    }
    inorder(n -> left);
    printf("%d ",n->data);
    inorder(n -> right);
}
// creating the preorder traversal program !!
void preorder(node n){
    if(n == NULL){
        return;
    }
    printf("%d ",n->data);
    preorder(n->left);
    preorder(n->right);
}
// creating the postorder traversal program !!
void postorder(node n){
    if(n == NULL){
        return;
    }
    postorder(n->left);
    postorder(n->right);
    printf("%d ",n->data);
}

// creating the main function for calling the function !!
int main(void){
    node root = NULL;
    root = create_tree(); // calling the create_tree function !!
    printf("Inorder traversal -> ");
    inorder(root); // calling the inorder function !!
    printf("\n");
    printf("Preorder traversal -> ");
    preorder(root); // calling the preorder function !!
    printf("\n");
    printf("Postorder traversal -> ");
    postorder(root); // calling the postorder function !!
    printf("\n");

    printf("Program successfully executed !! \n");
}