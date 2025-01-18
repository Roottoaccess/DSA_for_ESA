// Implementing the circular link list in C programming
#include<stdio.h>
#include<stdlib.h>

// creating a structure
typedef struct node{
    int data;
    struct node *link;
}*node;

// create node function
node create_node(int data){
    node head = (node) malloc (sizeof(struct node));
    if(head == NULL){
        printf("Memory Allocation failed !\n");
        return NULL;
    }

    head -> data = data;
    head -> link = head;

    return head;
}

// insert the node in the front !
node ins_in_front(int data, node head){
    node new_node = create_node(data);
    
    if(head == NULL){
        return create_node(data);
    }
    node temp = head;

    do{
        temp = temp -> link;
    }while(temp -> link != head); // traversing till the before

    temp -> link = new_node;
    new_node -> link = head;

    return new_node;
}

// creating the display function
void display(node head){
    if(head == NULL){
        printf("List is empty !");
        return;
    }
    node temp = head;
    printf("Head -> ");
    do{
        printf("%d -> ",temp -> data);
        temp = temp -> link;
    }while(temp != head); // traversing the full length !

    printf("Head \n");
}

// inserting in the rear part !
node ins_in_last(int data, node head){
    if(head == NULL){
        return create_node(data);
    }
    node new_node = create_node(data);
    node temp = head;
    do{
        temp = temp -> link;
    }while(temp -> link != head);

    temp -> link = new_node;
    new_node -> link = head;
    return head;
}

node del_in_front(node head){
    if(head == NULL){
        printf("There is no node present in the memory to display !");
        return NULL;
    }
    node demo = head;
    head = head -> link;
    node temp = head;
    do{
        temp = temp -> link;
    }while(temp -> link != demo);

    temp -> link =  head;
    free(demo);

    return head;
}

node del_in_rear(node head){
    node temp = head;
    do{
        temp = temp -> link;
    }while(temp -> link -> link != head);

    node demo = temp -> link;

    temp -> link = head;
    free(demo);

    return head;
}

// insert in position
node ins_in_pos(int data, node head, int pos){
    node new_node = create_node(data);
    if(pos == 0){
        return ins_in_front(data, head);
    }
    node temp = head;
    for(int i = 0; i < pos -1;i++){
        temp = temp -> link;
    }
    if(temp -> link == head){
        return ins_in_last(data, head);
    }
    new_node -> link = temp -> link;
    temp -> link = new_node;

    return head;
}

// delete in position
node del_in_pos(node head, int pos){
    node temp = head;
    if(pos == 0){
        return del_in_front(head);
    }
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }
    if(temp -> link == head){
        return del_in_rear(head);
    }
    node demo = temp -> link;
    temp -> link = temp -> link -> link;
    free(demo);

    return head;
}

int main(void){
    node n = create_node(2);
    display(n);
    n = ins_in_front(1, n);
    display(n);
    n = ins_in_last(4, n);
    display(n);
    // n = del_in_front(n);
    // display(n);
    // n = del_in_rear(n);
    // display(n);
    n = ins_in_pos(3 , n , 0);
    display(n);
    n = del_in_pos(n, 1);
    display(n);
}