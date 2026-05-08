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
        struct node* temp1 = head1;
        struct node* temp2 = head2;
        while(temp1->next !=NULL && temp2->next!=NULL){
            if(temp1->data == temp2->data){
                temp1 = temp1->next;
                temp2 = temp2->next;
                if(temp1==NULL && temp2!=NULL){
                    printf("list are not same !");
                    exit(1);
                }
                if(temp2==NULL && temp1!=NULL){
                    printf("list are not same ");
                    exit(1);
                }
            }

            else{
                printf("list are not same ");
            }

        }
    }
}


int main(){





    return 0;



}
