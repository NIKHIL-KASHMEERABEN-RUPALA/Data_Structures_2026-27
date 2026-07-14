#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

struct Node* createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int val){
    struct Node* newNode = createNode(val);
    if(last==NULL){
        newNode->next = newNode;
        last = newNode;
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

}



void display(struct Node *head){
    if(head==NULL){
        print("empty");
        return;
    }
    struct Node *temp = head;
    do{
        print(" %d ",temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("\n");
}


void splitList(){
     if (last == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    if (last->next == last)
    {
        printf("Only one node present.\n");

        printf("First Half : ");
        display(last->next);

        printf("Second Half : Empty\n");
        return;
    }


     struct Node *head = last->next;

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

     struct Node *head1 = head;
    struct Node *head2 = slow->next;
}



int main(){



    return 0;
}