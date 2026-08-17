#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node*next;
};

struct Node*front = NULL;
struct Node*rear = NULL;


void enqueue(int x){

    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL){
        printf("\n overflow ! memory not available");
        return;
    }
    newNode->info = x;
    newNode->next = NULL;
    if(front==NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}


void dequeue(){
    if(front==NULL){
        printf("\n Underflow ! ");
        return;
    }
    struct Node*temp = front;
    printf("\n Deleted %d successfully ",temp->info);
    front = front->next;
    if(front==NULL){
        rear = NULL;
    }
    free(temp);
}


void display(){
    if(front==NULL){
        printf("\n Queue is already empty ! ");
        return;
    }
    struct Node*temp = front;
    printf("\n Queue is :       \n");
    while(temp!=NULL){
        printf("\n %d ",temp->info);
        temp=temp->next;
    }


}


void peek()
{
    if (front == NULL)
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Front Element = %d\n", front->info);
}


int main()
{
    int choice, value;

    while (1)
    {
        printf("\n QUEUE USING LINKED LIST \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Program Ended.\n");
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}