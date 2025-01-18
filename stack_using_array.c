// This is the stack program using static array !!
#include<stdio.h>
#define max 5

// creating the array!
int arr[max];

int top = -1; // initializing the top of the array !

// creating the push operation !
void push(int data){
    if(top == max - 1){
        printf("Stack Overflow");
        return;
    }
    top++; // incrementing the top
    arr[top] = data;
    printf("Element %d pushed into the stack successfully !\n",data);
}

// creating the pop function !!
void pop(){
    if(top == -1){
        printf("Stack Underflow condition occured !");
        return;
    }
    int poped_ele = arr[top];
    top--; // decrementing the top variable (not removing the element) just pretending
    printf("%d element has beed poped !\n",poped_ele);
}

void display(){
    if(top == -1){
        printf("There is no node present in the stack to display \n");
    }
    printf("Displaying the stack -> \n");
    for(int i = top; i >= 0; i--){
        printf("\t | %d | \n",arr[i]);
    }
}

void peek(){
    if(top == -1){
        printf("There is no element present in the stack to display !");
        return;
    }
    printf("The peek element is -> %d \n", arr[top]);
}

int main(void){
    push(2);
    push(4);
    push(8);
    push(10);
    display();
    pop();
    display();
    peek();
    return 0;
}