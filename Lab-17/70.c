#include<stdio.h>
#include<stdlib.h>

int queue[5];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear>=5-1){
        printf("\n Queue Overflow ! ");
        return;
    }
    queue[++rear] = x;
    if(front==-1){
        front=0;
    }
}


int dequeue(){
    if(front==-1){
        printf("\n Queue underflow !");

        return;
    }

    int to_remove = queue[front];
    
    if(front==rear){
        front = rear = -1;
    }
    else{
        front = front+1;
    }
}