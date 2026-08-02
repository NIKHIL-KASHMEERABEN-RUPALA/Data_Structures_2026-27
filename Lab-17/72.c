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

int Cdequeue(){
    if(front==-1){
        printf("\n Cqueue underflow ! ");
        return;
    }
    int y = queue[front];
    if(front==rear){
        front = rear=-1;
    }
    else{
        front = (front+1)%5;
    }
    return y;
}

void display(){
    if(front==-1){
        printf("\n Cqueue is empty ! ");
        return;
    }

    int i = front;
    do{
        printf(" %d ",queue[i]);
        if(i==rear){
            break;
        }
        i = (i+1)%5;
    }while(i!=rear);
}