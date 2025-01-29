#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*node;

typedef struct pq{
    struct pq *np;
    int pr;
    struct node *start;
}*pq;
// First structure !!
node create_node(int data){
    node n = (node) malloc (sizeof(node));
    if(n == NULL){
        printf("Memory allocation failed !");
        return NULL;
    }
    n -> data = data;
    n -> link = NULL;
    return n;
}
// Second structure !
pq createpq(int pr){
    pq p = (pq) malloc (sizeof(pq));
    if(p == NULL){
        printf("Memory allocation failed !");
        return NULL;
    }
    p -> np= NULL;
    p -> start = NULL;
    p -> pr = pr;
    return p;
}
// Insertion !!
pq insert(pq q, int data, int pr){
    
}