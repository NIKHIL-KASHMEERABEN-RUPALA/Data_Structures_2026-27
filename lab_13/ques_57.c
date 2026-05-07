#include<stdio.h>
#include<stdlib.h>


struct node* head = NULL;


struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("\n The dynamic memory allocation has been failed \n");
        return NULL;
    }else{
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertFront(int value){
    struct node *newNode = createNode(value);
    if(head==NULL){
        newNode->next = NULL;
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }

    printf("\n Node inserted at starting successfully.\n");

}

void insertEnd(int value){
    struct node *newNode = createNode(value);
    if(head==NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("\n Node inserted at end successfully. \n");

}


void display(){

    if(head==NULL){
        printf("\n The singly linked list is empty \n");
    }else{
        struct node *t = head;
        while(t->next!=NULL){
            printf(" %d -> ",t->data);
        }
        printf(" NULL ");
    }


}

void deleteFront(){

    if(head==NULL){
        printf("\n THe list is already empty \n");
    }
    else{
        struct node* temp;
        temp = head;
        head = head->next;
        printf("\n Deleted the node %d \n",temp->data);
        free(temp);
    }

}

void deleteEnd(){

    if(head==NULL){
        printf("\n The list is already empty \n");
    }
    else{
        struct node*temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }

        printf("\n Removed %d from the end \n",temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }

}

void deletePosition(int val){
    if(head==NULL){
        printf("\n Bro the list is already empty ! \n");
    }

    if(val<0){
        printf("\n The value is invalid ]n");
    }

    else{
        struct node* temp = head;
        struct node* prev = head;
        for(int i = 1 ; i <val ; i++){
            prev = temp;
            temp=temp->next;
            if(temp==NULL){
                printf("\n The position is out of range ! \n");
            }
        }
        printf("Removed the data : %d ",temp->data);
        prev->next = temp->next;
        free(temp);
        
    }
}


void countNodes(){
    int count = 1 ;
    struct node* temp = head;

    if(head==NULL){
        count = 0;
        printf("Singly linked list is empty !");
    }

    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }

    printf("\n The total number of nodes are :     %d     ",count);

}




int main(){


    


    return 0;

}