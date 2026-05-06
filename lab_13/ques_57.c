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
    else{
        struct node* temp = head;
        int value = val;
        for(int i = 0 ; i <val ; i++){
            temp=temp->next;
        }
    }
}




int main(){


    


    return 0;

}