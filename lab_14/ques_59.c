// WAP to check whether 2 singly linked lists are same or not.
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


struct node{
    int data;
    struct node* next;
};


struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("\n dynamic mem allocation has been failed \n");
    }
    newNode->data = data;
    newNode->next = NULL;
}

bool check_list(struct node*head1 , struct node*head2){

    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while(temp1 != NULL && temp2!= NULL){
        if(temp1->data != temp2->data){
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return (temp1 == NULL && temp2 == NULL);

}


int main(){

    struct node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);

    struct node* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);

    if(check_list(head1,head2)){
        printf("Both list are same ");
    }else{
        printf("List are not same ");
    }




    return 0;
}