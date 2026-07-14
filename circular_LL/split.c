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

     slow->next = head1;
     fast->next = head2;

    printf("\nFirst Half : ");
    display(head1);

    printf("\n Second Half : ");
    display(head2);

}


int main()
{
    int n, value;

    printf("Enter number of nodes : ");
    scanf("%d", &n);

    printf("Enter elements :\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertEnd(value);
    }

    printf("\nOriginal Circular Linked List : ");
    display(last->next);

    splitList();

    return 0;
}