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


void deleteAtPosition(int pos){
    if(head==NULL){
        printf("DOubly ll is empty ");
        return;
    }

    struct Node *temp = head;

    if(pos==1){
        head = head->next;
        if(head!=NULL){
            head->prev = NULL;
        }
        free(temp);
    }

    for(int i = 1 ; i<pos && temp!=NULL ; i++){
        temp = temp->next;
    }

    if(temp==NULL){
        printf("\n Invalid position ! ");
    }

    temp->prev->next = temp->next;

    if(temp!=NULL){
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("\n Node deleted successfully ! ");
}


void display(){
    if(head==NULL){
        printf("\n Doubly LL is empty ! ");
    }

    struct Node *temp = head;
    while(temp!=NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
