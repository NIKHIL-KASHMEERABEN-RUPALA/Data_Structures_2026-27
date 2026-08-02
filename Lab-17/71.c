#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node*next;
};

struct Node*front = NULL;
struct Node*rear = NULL;


void enqueue(int x){

    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL){
        printf("\n overflow ! memory not available");
        return;
    }
    newNode->info = x;
    newNode->next = NULL;
    if(front==NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}