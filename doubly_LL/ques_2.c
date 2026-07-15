#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};
struct Node*head=NULL;

struct Node *createNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(int val){
    struct Node *newNode = createNode(val);
    if(head==NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val){
    struct Node *newNode = createNode(val);
    if(head==NULL){
        head = newNode;
        return;
    }
    struct Node*temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void display()
{
    if (head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void deleteAlternateNodes(){
    // checking base case 
    // if one node or no node is present 
    if(head==NULL || head->next==NULL){
        return;
    }

    struct Node*temp = head->next;
    while(temp!=NULL){
        struct Node *nextNode = temp->next;
        
        temp->prev->next = nextNode;
        if(temp->next!=NULL){
            temp->next->prev = temp->prev;
        }
        free(temp);
        if(nextNode!=NULL){
            temp = nextNode->next;
        }
        else{
            temp = NULL;
        }
    }
}