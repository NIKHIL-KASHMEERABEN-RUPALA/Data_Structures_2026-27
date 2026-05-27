#include<stdio.h>
#define size 20

int dqueue[size];
int front = -1;
int rear = -1;

void insertFront(){
    if(front==0){
        printf("\n doubly ended queue is already full ! ");
    }
    else if(front==-1){
        front = rear = 0;
    }
    else{
        front--;
    }

    int element;

    printf("\n Enter the element to insert :        ");
    scanf("%d",&element);

    dqueue[front] = element;
}



void insertRear(){
    if(rear == size-1){
        printf("\n full from back side or rear side ! ");
    }
    else{
        if(front==-1){
            front = rear = 0;
        }
        else{
            rear++;
        }
    }
    int to_insert;
    printf("\n Enter element to insert at rear :        ");
    scanf("%d",&to_insert);
    dqueue[rear] = to_insert;
}



