#include<stdio.h>
#define size 20

int dqueue[size];
int front = -1;
int rear = -1;

void insertFront(){
    if(front==0){
        printf("\n doubly ended queue is already full ! ");
        return;
    }
    else if(front==-1){
        front = rear = 0;
    }
    else{
        front--;
    }

    int element;

    printf("\n Enter the element to insert :        ");
    scanf("%d",&element);

    dqueue[front] = element;
}



void insertRear(){
    if(rear == size-1){
        printf("\n full from back side or rear side ! ");
        return;
    }
    else{
        if(front==-1){
            front = rear = 0;
        }
        else{
            rear++;
        }
    }
    int to_insert;
    printf("\n Enter element to insert at rear :        ");
    scanf("%d",&to_insert);
    dqueue[rear] = to_insert;
}


void deleteFront(){
    if(front==-1){
        printf("\n The queue is already empty !");
    }
    else{
         
        printf("\nDeleted element from front: %d\n", dqueue[front]);
        if(front == rear){
            front = rear = -1;
        }
        else{
            front++;
        }
    }
}


void deleteEnd(){
    if(front==-1){
        printf("\n Deleting from the back is not possible !");
    }
    else{
        printf("\nDeleted element from rear: %d\n", dqueue[rear]);
        if(front == rear){
            front = rear = -1;
        }
        else{
            rear--;
        }
    }
}



void display(){
    if(front==-1){
        printf("\n Dequeue is empty ");
    }
    else{
        printf("\n The elements are ------ ");
        for(int i = front ; i<= rear ; i++){
            printf(" %d",dqueue[i]);
        }
    }
}


int main(){

    int choice;

    do{

        printf("\n Enter a choice ------- ");
        printf("\n 1. Insert at front ");
        printf("\n 2. Insert at end ");
        printf("\n 3. Delete at front ");
        printf("\n 4. Delete at end ");
        printf("\n 5. Display the elements ");
        printf("\n 6. Exit the programme ");
        scanf("%d",&choice);


         switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("\n Program exited ");
                break;

            default:
                printf("\nInvalid choice!\n");
        }


    } while(choice!=6);



    return 0;
}


