#include <stdio.h>
#include <stdlib.h>

// Creating a structure
typedef struct node {
    int data;
    struct node *link;
} *node;

// Create node function
node create_node(int data) {
    node new_node = (node)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory Allocation failed!\n");
        return NULL;
    }

    new_node->data = data;
    new_node->link = new_node;

    return new_node;
}

// Creating the display function
void display(node head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node temp = head;
    printf("Head -> ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != head);

    printf("Head\n");
}

// Insert the node in the front
node ins_in_front(int data, node head) {
    node new_node = create_node(data);

    if (head == NULL) {
        return new_node;
    }

    node temp = head;
    while (temp->link != head) {
        temp = temp->link;
    }
    temp->link = new_node;
    new_node->link = head;

    return new_node;
}

int main(void) {
    node n = create_node(2);
    display(n);
    n = ins_in_front(1, n);
    display(n);
    n = ins_in_front(4, n);
    display(n);

    return 0;
}