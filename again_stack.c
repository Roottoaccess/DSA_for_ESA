// array implementation
#include<stdio.h>
#define max 5
int arr[max];
int top = -1;


void push(int data){ // Only push the element
    if(top == max - 1){
        printf("Stack Overflow condition !\n");
        return;
    }
    top++;
    arr[top] = data;
    printf("Element %d pushed successfully !\n",data);
}

void pop(){ // Only pop the element
    if(top == -1){
        printf("Stack Underflow condition !\n");
    }
    int store = arr[top];
    top--;
    printf("%d is poped !\n",store);
}

void display(){
    if(top == -1){
        printf("Stack is Empty nothing to display \n");
        return;
    }
    for(int i = top; i >= 0; i--){
        printf("\t\t | %d | \n",arr[i]);
    }
}

void peek(){
    if(top == -1){
        printf("There is no node present in the memory to show thw peek\n");
        return;
    }
    printf("PEEK Element of the stack is -> %d\n",arr[top]);
}

int main(void){
    push(2);
    push(5);
    push(7);
    push(15);
    push(14);
    push(22);
    display();
    pop();
    display();
    peek();
}