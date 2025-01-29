// Implementing the circular queue operation using array
#include<stdio.h>
#define max 5
int queue[max];
int front = -1; int rear = -1;

// Implementing the Enqueue operation!
void Enqueue(int data){
    if(front == -1 && rear == -1){ // checking if the queue is empty ?
        front = rear = 0;
        queue[rear] = data;
    } else if(((rear + 1) % max) == front){
        printf("Queue is full !\n");
        return;
    }
    rear = (rear+1)%max; // Formul for the checking !
    queue[rear] = data; // pushing the data into the queue !
}

// Implementing the Dequeue operation!
void Dequeue(){ 
    if(front == -1 && rear == -1){ // checking if the queue is empty ?
        printf("Queue is empty so Dequeue operation will not work !\n");
        return; 
    }else if(front == rear){
        printf("%d is the Dequeued element \n",queue[front]);
        front = rear = -1;
    } else{
        printf("%d -> is the Dequeued element",queue[front]);
        front = (front + 1) % max;
    }
}

// Implementing the display function
void display(){
    int i = front;
    if(front == -1 && rear == -1){
        printf("The Queue is Empty nothing to display!\n");
        return;
    }
    else{printf("Queue is: ");
        while(i != rear){
            printf("|%d|\n",queue[i]);
            i = (i + 1) % max;
        } 
        printf("|%d|\n",queue[rear]);
    }
}

// Implementing the PEEK operation
void peek(){
    if(front == -1 && rear == -1){
        printf("The queue is Empty !\n");
        return;
    } printf("{%d} -> PEEK\n",queue[front]);
}


int main(void){
    Enqueue(12);
    Enqueue(10);
    Enqueue(22);
    Enqueue(88);
    display();
    Dequeue();
    // peek();
    display();
    return 0;
}