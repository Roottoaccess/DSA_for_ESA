// queue using link list
#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int data;
    struct queue *link;
}*queue;

queue First_Enqueue(int data){ // This is for the first queue implementation
    queue q = (queue) malloc (sizeof(queue));
    if(q == NULL){
        printf("Memory allocation failed !\n");
        return NULL;
    }
    q -> data = data;
    q -> link = NULL;
    return q;
}
/* Queue -> FIFO (first in first out principle) 
    |5 | 6 | 8 | 10| -> FIFO
    [5]-[6]-[8]-[10]<- insertion is happening from here !
    OPERATION -> Enqueue, Dequeue, peek, display !!
*/
queue Enqueue(int data, queue q){ // Enqueue operation for queue !
    // insert in the last in link list
    queue new_data = First_Enqueue(data);
    queue temp = q;
    while(temp -> link != NULL){
        temp = temp -> link;
    } temp -> link = new_data;
    return q;
}

queue Dequeue(queue q){ // Dequeue operation for queue !
    if(q == NULL){
        printf("The queue is empty, so deqeue is not possible !");
        return NULL;
    }
    queue hold = q;
    q = q -> link;
    free(hold);
    return q;
}

void display(queue q){ // Display operation for queue !
    if(q == NULL){
        printf("There is nothing inside the queue to display !");
    }
    printf("Front -> ");
    while(q != NULL){
        printf("| %d | ",q->data);
        q = q -> link;
    }printf("<- Rear \n");
}


void peek(queue q){ // peek function of the queue !
    if(q == NULL){
        printf("Queue is Empty !\n");
        return;
    }
    printf("\t\t{%d} is the PEEK in the queue\n",q -> data);
}

int main(void){
    queue n = First_Enqueue(2);
    n = Enqueue(4, n);
    n = Enqueue(18, n);
    n = Enqueue(28, n);
    n = Enqueue(88, n);
    n = Enqueue(188, n);
    n = Enqueue(8, n);
    display(n);
    n = Dequeue(n);
    display(n);
    peek(n);
}