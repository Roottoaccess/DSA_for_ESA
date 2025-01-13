// doubly link list implementation !!
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}*node;

node create_node(int data){
    node head = (node) malloc (sizeof(struct node));

    if(head == NULL){
        printf("Memory allocation fialed !");
    }

    head -> data = data;
    head -> next = NULL;
    head -> prev = NULL;

    return head;
}

void display(node head){
    if(head == NULL){
        printf("There is no node present in the memory to display !\n");
    }
    printf("Head -> ");
    while(head != NULL){
        printf("%d <-> ", head -> data);
        head = head -> next;
    }
    printf("NULL \n");
}

node ins_in_front(node head, int data){ // inserting the node in the front !
    if(head == NULL){
        return create_node(data);
    }
    // node temp = head;
    node new_node = create_node(data);

    new_node -> next = head;
    new_node -> prev = NULL;
    head -> prev = new_node;

    return new_node;
}

// inserting the node in the last !
node ins_in_rear(node head, int data){
    if(head == NULL){
        return create_node(data);
    }
    node temp = head;
    node new_node = create_node(data);
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = new_node;
    new_node -> prev = temp;
    new_node -> next = NULL;

    return head;
}
// creating the ins_in_position
node ins_in_pos(node head, int data, int pos){
    if(pos == 0){
        return ins_in_front(head, data);
    }
    node temp = head;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }
    if(temp -> next == NULL){
        return ins_in_rear(head, data);
    }

    node new_node = create_node(data);
    new_node -> next = temp -> next;
    temp -> next -> prev = new_node;
    temp -> next = new_node;
    new_node -> prev = temp;

    return head;
}

node del_in_front(node head){ // deleting the first node !
    if(head == NULL){
        printf("There is no node present in the memory to display !\n");
    }
    node temp = head;

    head = head -> next;
    head -> prev = NULL;

    free(temp);

    return head;
}

// deleting the node in the rear section !
node del_in_rear(node head){
    if(head == NULL){
        printf("There is no node present in the memory to display !\n");
    }

    node temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    node demo = temp -> next;

    demo -> prev -> next = NULL;

    free(demo);

    return head;
}

// creating the delete_in_position
node del_in_pos(node head, int pos){
    if(pos == 0){
        return del_in_front(head);
    }

    node temp = head;
    for(int i = 0; i < pos - 1;i++){
        temp = temp -> next;
    }
    if(temp -> next == NULL){
        return del_in_rear(head);
    }
    node demo = temp -> next;
    temp -> next = temp -> next -> next;
    if(temp -> next != NULL){
        temp -> next -> prev = temp;
    }
    free(demo);
    return head;
}

int main(void){
    node head = create_node(2);
    head = ins_in_front(head, 4);
    head = ins_in_rear(head, 6);
    head = ins_in_pos(head, 5, 2);
    // head = del_in_front(head);
    // head = del_in_rear(head);
    head = del_in_pos(head, 2);
    display(head);
}