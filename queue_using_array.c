// Queue implentation using array
#include<stdio.h> 
#define max 5
int queue[max];
int rear = -1; int front = -1;
/* Queue -> FIFO (first in first out principle) 
    |5 | 6 | 8 | 10| -> FIFO
    [5]-[6]-[8]-[10]<- insertion is happening from here !
    OPERATION -> Enqueue, Dequeue, peek, display !!
*/
void Enque(int data){ // Enqueue operation !
    if(rear == max - 1){
        printf("Overflow Condition occured !\n");
        return;
    } else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = data;
    } else{
        rear++;
        queue[rear] = data;
    }
}

void Dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow Condition !\n");
        return;
    }
    else if(front == rear){
        front = rear = -1;
    } else {
        printf("\t\t%d Dequeued !\n",queue[front]);
        front++;
    }
}

void display(){ // creating the display function
    if(front == -1 && rear == -1){
        printf("Queue is empty nothing to display !\n");
        return;
    } else{
        for(int i = front; i <= rear; i++){
            printf("| %d | \n",queue[i]);
        }
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow Condition occured !\n");
        return;
    } printf("\t\t%d -> is the peek of the queue\n",queue[front]);
}

int main(void){
    Enque(2);
    Enque(4);
    Enque(18);
    Enque(88);
    Enque(22);
    display();
    Dequeue();
    display();
    peek();
}