// implementing the singly link list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{ // creating the structure of the node !
    int data;
    struct node *link;
}*node;

node create_node(int data){ // creating the node !
    node head = (node) malloc (sizeof(node));

    if (head == NULL){
        printf("Memory allocation failed !\n");
    }

    head -> data = data;
    head -> link = NULL;

    return head;
}

node ins_in_front(node head, int data){
    if(head == NULL){
        return create_node(data);
    }
    // creating another node !

    node new_node = create_node(data);
    
    new_node -> link = head;

    return new_node;
}

node ins_in_last(node head, int data){
    if(head == NULL){
        return create_node(data);
    }
    // creating the new node
    node new_node = create_node(data);
    node temp = head;
    while(temp -> link != NULL){
        temp = temp -> link;
    }

    temp -> link = new_node;

    return head;
}

node del_front(node head){
    if(head == NULL){
        printf("There is no node present in the memory !\n");
    }
    node temp = head;
    head = head -> link;

    free(temp); // removing temp and free the memory !

    return head;
}

node del_rear(node head){
    if(head == NULL){
        printf("There is no node present in the memory !\n");
    }
    node temp = head;
    while(temp -> link -> link != NULL){
        temp = temp -> link;
    }
    node demo = temp -> link;
    temp -> link = NULL;

    free(demo);

    return head;
}

// creating the ins_in_position
node ins_in_position(node head, int data, int pos){
    if(head == NULL){
        printf("There is no node present in the memory to perform the insert in position\n");
        
    }
    if(pos == 0){
        return ins_in_front(head, data);
    }
    node new_node = create_node(data);
    node temp = head;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    } 
    if(temp -> link == NULL){
        return ins_in_last(head, data);
    }

    new_node -> link = temp -> link;
    temp -> link = new_node;

    return head;
}

node del_pos(node head, int pos){
    if(head == NULL){
        printf("There is no node present in the memory to perform the delete in position !\n");
    }
    if(pos == 0){
        return del_front(head);
    }
    node temp = head;
    for(int i = 0; i < pos - 1;i++){
        temp = temp -> link;
    }
    if(temp -> link == NULL){
        return del_rear(head);
    }
    node demo = temp -> link;
    temp -> link = temp -> link -> link;
    free(demo);

    return head;
}

void sorted_list(node head){
    for(int i = head; )
}

void display(node head){
    if(head == NULL){
        printf("There is no node present in the memory to display !\n");
    }

    printf("HEAD -> ");
    while(head != NULL){
        printf("%d -> ", head -> data);
        head = head -> link;
    }
    printf("NULL \n");
}

int main(void){
    node head = create_node(4);
    display(head);
    head = ins_in_front(head, 2);
    display(head);
    head = ins_in_last(head, 8);
    display(head);
    // head = del_front(head);
    // display(head);
    // head = del_rear(head);
    // display(head);
    head = ins_in_position(head, 5, 2);
    display(head);
    head = del_pos(head, 2);
    display(head);
}