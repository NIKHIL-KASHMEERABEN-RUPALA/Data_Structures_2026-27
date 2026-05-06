#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// just creating a node 

struct Node* createNode(int value){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Dynamic memory allocation has been failed \n");
    }
    newNode->data=value;
    newNode->next=NULL;

    return newNode;
}

// reading the data inside a node 

void readData(struct Node* node){

    if(node==NULL){
        printf("\n The node is invalid \n");
    }

    printf("\n Enter the data part of the node :            ");
    scanf("%d",node->data);


}



// printing the node 

void printNode(struct Node* node){
    if(node==NULL){
        printf("\n The node is invalid");
    }

    printf("\n The node data is :    %d   ",node->data);
    printf("\n next node address is :      %p     ",(void *)node->next);
    printf("\n Current node address is :    %p    ",(void *)node);



}


int main(){



    return 0;
}