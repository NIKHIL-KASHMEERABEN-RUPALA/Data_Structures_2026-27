#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};

struct Node*head = NULL;

struct Node * createNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
}

void insertAtFront(int val){
    struct Node*newNode = createNode(val);
    if(head==NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev=newNode;
    head = newNode;
}

void insertAtEnd(int val){
    struct Node*newNode = createNode(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    struct Node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Node has been inserted at the end ");
}