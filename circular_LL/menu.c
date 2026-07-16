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
    if(last==NULL){
        printf("\n This is empty Circular Linked List ");
    }
    struct Node*current = last;
    struct Node*head = last->next;
    if(pos==1){
        if(last==current){
            free(current);
            last = NULL;
            return;
        }
        last->next = current->next;
        free(current);
        return;
    }

    int count = 1;
    struct Node*prev=last;
    while(count<pos && head!=last){
        prev=head;
        

    }

}