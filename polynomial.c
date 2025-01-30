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
/* This is the insert in front function */
node ins_in_front(node head, int coef, int Exp){
    node new_node = create_node(coef, Exp); // Created the node !
    new_node -> link = head;
    return new_node;
}
/* This is the insert in last function */
node ins_in_last(node head, int coef, int Exp){
    node new_node = create_node(coef, Exp); // Created the node !
    node temp = head;

    while(temp -> link != NULL){
        temp = temp -> link;
    }
    temp -> link = new_node;
    new_node -> link = NULL;
    return head;
}

node insert_node(node head, int coef, int Exp){
    node new_node = create_node(coef, Exp); // Created the node !
    if(new_node -> Exp > head -> Exp){
        return ins_in_front(head, coef, Exp);
    } else if(new_node -> Exp < head -> Exp ){

    }
     else{
        return ins_in_last(head, coef, Exp);
    }
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
    head = insert_node(head, 5, 5); display(head);
    head = insert_node(head, 6, 2); display(head);
    head = insert_node(head, 9, 1); display(head);
    head = insert_node(head, 4, 4); display(head);
}