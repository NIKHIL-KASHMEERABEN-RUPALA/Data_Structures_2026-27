// WAP to check whether 2 singly linked lists are same or not.

#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;

};


struct node* createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("\n Dynamic memory allocation has been failed \n");
        return NULL;
    }
    else{
        newNode->data = value;
        newNode->next = NULL;     
        
    }
    return newNode;
}


void check_List(struct node* head1 , struct node* head2){
    if(head1==NULL && head2 != NULL){
        printf("\n List are not same , because ---- ");
        printf("First list is empty while second list is not empty ! \n");
    }else{
        if(head1!=NULL && head2==NULL){
            printf("\n List are not same , because ---- ");
            printf(" Second list is empty while the first list is empty \n");
        }
        if(head1==NULL && head2==NULL){
            printf("\n Both list are same \n");
        }
    }
}


int main(){





    return 0;



}
