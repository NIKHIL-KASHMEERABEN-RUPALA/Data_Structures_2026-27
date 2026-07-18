#include<stdio.h>
struct Node{
    int data;
    struct Node*next;
};

struct Node *top = NULL;

void push(){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("\n Physical Stack overflow ! system capacity reached at peak ");
        return;
    }
    printf("\n Enter the value to be pushed :     ");
    scanf("%d",&newNode->data);
    newNode->next =top;
    top = newNode;
    printf("%d inserted successfully.\n", newNode->data);
}


void pop(){
    if(top==NULL){
        printf("\n The stack is empty ! ");
        return;
    }
    struct Node*temp = top;
    printf("\n Popped value = %d ",top->data);
    top = top->next;
    free(temp);
}


void display(){
    struct Node* temp ;
    if(top==NULL){
        printf("\n Stack is empty ! ");
        return;
    }
    temp = top;
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp = temp->next;
    }
    printf("\n Entire list has been printed successfully ! ");
}

void peep(){
    if(top==-1){
        printf("Stack is already empty , so nothing to peep ! ");
        return;
    }
    struct Node*temp = top;
    printf("\n Enter the position to peep from top :        ");
    int position;
    scanf("%d",&position);
    int i = 1;
    while(i<position && temp!=NULL){
        temp = temp->next;
        i++;
    }
    if(temp==NULL){
        printf("\n Invalid position ! ");
    }
    printf("%d is the element you wanted to peep ",temp->data);
}