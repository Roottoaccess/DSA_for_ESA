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

node ins_in_front(node head, int coef, int Exp){
    node new_node = create_node(coef, Exp); // Created the node !
    new_node -> link = head;
    return new_node;
}

// node insert_node(node head, int coef, int Exp){
//     node new_node = create_node(coef, Exp); // Created the node !
//     node temp = head;
//     while(temp -> link != NULL){
//         if(temp -> Exp < new_node -> Exp){
            
//         }
//         temp = temp -> link;
//     }
// }

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
    head = ins_in_front(head, 2, 5); display(head);
}