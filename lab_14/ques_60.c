#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int value){

    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("\n Dyanmic memory allocation has been failed \n");
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}


void dupli_check(struct node* head1){
    struct node* temp1 = head1;
    struct node* duplicate;
    while(temp1 != NULL && temp1->next!=NULL){
        if(temp1->data == temp1->next->data){
            duplicate = temp1->next;
            temp1->next = temp1->next->next;
            free(duplicate);
        }
        else{

            temp1 = temp1->next;

        }
        

    }
}



void display(struct node* head1){
    struct node* temp = head1 ;
    while(temp->next!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf(" NULL ");
}


int main(){




    return 0;
}