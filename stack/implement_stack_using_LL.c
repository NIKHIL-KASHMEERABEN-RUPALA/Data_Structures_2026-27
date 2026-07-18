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


