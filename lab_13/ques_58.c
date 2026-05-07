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


    int choice= 0;

    do
    {
    
        printf("\n Enter your choice :          \n");
        printf("\n 1. Insert at first \n");
        printf("\n 2. Insert at end \n");
        printf("\n 3. delete at first \n");
        printf("\n 4. delete at end \n");
        printf("\n 5. delete at nth position \n");
        printf("\n 6. exit the programme \n");
        
        scanf("%d",&choice);


        switch(choice){
            case 1:
                int n;
                printf("\n Enter the value to insert :     ");
                scanf("%d",&n);
                insertFront(n);
                break;

            case 2:
                int n;
                printf("\n Enter the value to insert :      ");
                scanf("%d",&n);
                insertEnd(n);
                break;


            case 3:
                deleteFront();
                break;
            
            case 4:
                deleteEnd();
                break;

            case 5:
                int n;
                printf("Enter the value to delete :     ");
                scanf("%d",&n);
                deletePosition(n);
                break;

            case 6:
                printf("\n The programme has been terminated \n");
                break;


            case 7:
                countNodes();
                break;

            
            
       


        }


    }
    
    while(choice!=6);


    return 0;

}