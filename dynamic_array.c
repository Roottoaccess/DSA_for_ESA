#include<stdio.h>
#include<stdlib.h>
#define max 5

int arr[max];
int top = -1;
typedef struct po{ // Creating the structure !
    struct po *link;
}*po;

