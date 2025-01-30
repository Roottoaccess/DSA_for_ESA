/*
        ┌───────────────┐      ┌───────────────┐     ┌───────────────┐
HEAD -> │ Coef: 4,Exp: 3│ ->   │ Coef: 3,Exp: 2│ ->  │ Coef: 1, Exp:0│   -> NULL
        └───────────────┘      └───────────────┘     └───────────────┘
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{ // Creating the structure for the program !!
    int coef;
    int Exp;
    struct node *link; /* Pointer for the link */
}*node;

/* {4x^3 + 3x^2 + 1} */

node create_node(int coef, int Exp){
    node head = (node) malloc (sizeof(node));

    if(head == NULL){
        printf("Memory allocation failed !");
        return NULL;
    }

    head -> coef = coef;
    head -> Exp = Exp;
    head -> link = NULL;

    return head;
}

node insert_node(){

}

void display(node head){
    if(head == NULL){
        printf("Nothing to print because there is no node");
    }
    printf("head -> ");
    while(head != NULL){
        printf("|%d|x^|%d|-> ",head -> coef, head -> Exp);
        head = head -> link;
    } printf("NULL \n");
}

int main(void){
    node head = NULL;
    head = create_node(4, 3);
    display(head);
}