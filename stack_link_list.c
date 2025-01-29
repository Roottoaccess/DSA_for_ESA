// // stack -> (LIFO) last in first out
/*
    8
    5
    4
    3
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *link;
} *node;

// Create a new node
node first_element(int data) {
    node n = (node)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    n->data = data;
    n->link = NULL;
    return n;
}

// Push a new element to the stack
node push(node n, int data) {
    node new_element = first_element(data);
    if (new_element == NULL) {
        return n; // Return existing stack if memory allocation fails
    }
    new_element->link = n;
    return new_element;
}

// Pop the top element from the stack
node pop(node n) {
    if (n == NULL) {
        printf("There is no node present in the stack to pop.\n");
        return NULL;
    }
    node temp = n;
    n = n->link;
    free(temp);
    return n;
}

// Display the stack elements
void display(node n) {
    if (n == NULL) {
        printf("There is no element in the stack!\n");
        return;
    }
    printf("Stack elements:\n");
    while (n != NULL) {
        printf("\t\t| %d |\n", n->data);
        n = n->link;
    }
    printf("\n");
}

void peek(node n){
    if(n == NULL){
        printf("No node present !");
        return;
    }
    printf("PEEK -> {%d}\n",n -> data);
}

// Main function to test stack operations
int main(void) {
    node head = NULL; // Initialize stack as empty

    // Push elements to the stack
    head = push(head, 2);
    head = push(head, 4);
    head = push(head, 8);

    // Display the stack
    display(head);

    // Pop an element and display the stack
    head = pop(head);
    printf("After popping one element:\n");
    display(head);

    // Pop all elements and display
    // head = pop(head);
    // head = pop(head);
    // head = pop(head); // Attempt to pop from an empty stack
    // printf("Final stack state:\n");
    // display(head);

    peek(head);

    return 0;
}
