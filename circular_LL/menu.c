#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};
struct Node *last = NULL;

struct Node *createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(int val){
    struct Node *newNode = createNode(val);
    if(last==NULL){
        last = newNode;
        last->next = newNode;
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
}

void insertAtEnd(int val){
    struct Node *newNode = createNode(val);
    if(last==NULL){
        last = newNode;
        last->next = newNode;
        return;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void deletePosition(int pos){
    
}