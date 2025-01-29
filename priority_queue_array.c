#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct PQ{
    int arr[max];
    int f , r, ct
}*PQ;

PQ initPQ(){
    PQ p = (PQ) malloc (sizeof(struct PQ));
    if(p == NULL){
        printf("Memeory allocation failed !");
        return NULL;
    }
    p -> arr[ele] = ele;

}

PQ insert(PQ q, int data, int pr){
    if(q->ct == max){
        printf("PQ is full");
    }
}