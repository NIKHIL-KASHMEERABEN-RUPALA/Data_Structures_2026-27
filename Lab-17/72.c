#include<stdio.h>
int queue[5];

int front = -1;
int rear = -1;

void Cenqueue(int x){
    if((rear+1)%5==front){
        printf("\n Overflow !");
        return;
    }
    rear = (rear+1)%5;
    queue[rear] = x;
    if(front==-1){
        front = 0;
    }
}