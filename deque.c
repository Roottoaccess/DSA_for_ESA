#include<stdio.h>
#include<stdlib.h>
#define max 5
// Deque ADT
typedef struct Deque{
    int arr[max];
    int f, r;
}*Deque;
// Insertion and deltion can happn in both the ends !!
Deque createDeque(){
    Deque d = (Deque) malloc(sizeof(struct Deque));

    if(d == NULL){
        printf("Memory allocation is failed !");
        return d;
    }

    d -> f = d -> r = -1;
    return d;
}

int isEmpty(Deque d){
    return d -> f == -1 && d -> r == -1;
}
// The count is (R - F + 1)
int isFull(Deque d){
    return (d -> r - d -> f + 1) == max;
}

// ins at front , ins at rear , del at rear, del at front

Deque enqueueRear(Deque d, int ele){
    // Enqueue the element at rear
    if(isFull(d)){ // if the queue is full !
        printf("Deque is full \n");
        return d;
    }

    if(isEmpty(d)){ // both pointer will come to zero !!
        d -> f = 0;
    }
    (d -> r)++;
    d -> arr[d -> r] = ele;
    return d;
}

Deque dequeueFront(Deque d){
    if(isEmpty(d)){
        printf("Deque is empty\n");
        return d;
    }
    printf("%d is deleted from front \n",d -> arr[d -> f]);
    if(d -> f == d -> r){
        printf("Last element deleted\n");
        d->f = d -> r = -1;
        return d;
    }
    (d -> f)++;
    return d;
}

Deque enqueueFront(Deque d, int ele){
    if(isFull(d)){
        printf("Deque is full\n");
        return d;
    }
    if(isEmpty(d)){
        d -> r = d -> f = 0;
        d->arr[d->f] = ele;
        return d;
    }
    if(d->f == 0){
        for(int i = (d -> r) + 1; i > 0; i--){
            d -> arr[i] = d -> arr[i + 1];
            (d -> r)++;
            d -> arr[d -> f] = ele;
            return d;
        }
    }
    (d -> f)--;
    d -> arr[d -> f] = ele;
    return d;
}

Deque dequeueRear(Deque d){
    if(isEmpty(d)){
        printf("Deque is empty\n");
        return d;
    }

    printf("%d is deleted from rear\n",
    d -> arr[d -> r]);
    if(d -> f == d -> r){
        printf("Delete the last element \n");
        d -> f = d -> r = -1;
        return d;
    }
    (d -> r)--;
    return d;
}

void peek(Deque d){
    return "";
}

void traverseDeque(Deque d){
    if(isEmpty(d)){
        printf("Deque is empty \n");
        return; 
    }
    printf("Deque: \n Front --> ");
    for(int i = d -> f; i <= d -> r; i++){
        printf("%d --> ", d -> arr[i]);
    }
    printf("Rear\n");
}

// entry restrict deck (restrict to front not in rear)
// Deleting can happen in both end

// Exit Restricted (restrict to rear not in front)
// Inserting can happen from both end