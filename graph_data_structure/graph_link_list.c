// This is the graph representation using link list implementation

#include<stdio.h>
#include<stdlib.h>

#define maxNode 4 // This is the total number of vertices that we are going to implement in this program

typedef struct node{
    int vertexNum;
    struct node *next;
}*node;

typedef struct list{
    node *head;
}*list;

list adjlist[maxNode] = {0};

// Adding the node in the graph
void addNode(int s, int d){

    if(adjlist[s]->head == NULL){
        node src = (node) malloc (sizeof(node));
        src -> vertexNum = s;
        src -> next = NULL;
        src = adjlist[s] -> head;
    }

    node dest = (node) malloc (sizeof(node));
    dest -> vertexNum = d;
    dest -> next = NULL;
    node temp = adjlist[s] -> head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = dest;
}

void printList(){
    for(int i = 1; i < maxNode; i++){
        node p = adjlist[i] -> head;
        printf("Adjacent list for vertex %d\n", i);


        while(p){
            printf("%d",p->vertexNum);
            p = p -> next;
        }
        printf("\n");
    }
}


int main(void){
    for(int i = 0; i < maxNode;i++){
        adjlist[i] = (list) malloc (sizeof(list));
        adjlist[i] -> head = NULL;
    }
    addNode(0, 1);
    addNode(0, 3);
    addNode(1, 2);
    printList();
}