#include<stdio.h>
#define size 20

int queue[size];
int front = -1;
int rear = -1;



void enqueue(int value){

    if(rear==size-1){
        printf("\n Queue overflow condition ! ");
    }

    else{


        if(front==-1){
            front = 0 ;
        }
        rear++;
        queue[rear] = value;

        printf("\n Inserted %d successfully ! ",value);

        }

}



void dequeue(){
    if(front==-1 || front>rear){
        printf("\n queue underflow ! ");
    }
    else{
        int removed = queue[front];
        printf("\n Removed %d successfully ! ",removed);
        front++;
    

        if(front>rear){
            front = -1;
            rear = -1;
        }

        }
    
}



void display(){
    if(front==-1 || front>rear){
        printf("\n Queue is already empty !");
    }
    else{
        printf("\nQueue elements are:\n");

        for(int i = front ; i <= rear ; i++){
            printf(" %d ",queue[i]);
        }
        printf("\n");
    }
}


int main(){


    int choice , value;

    do{
        printf("\n Enter a choice from following ------- ");
        printf("\n 1. Enqueue ");
        printf("\n 2. Dequeue ");
        printf("\n 3. Display ");
        printf("\n 4. Exit");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\n Enter the value to insert :      ");
                scanf("%d",&value);
                enqueue(value);
                break;
            
            case 2:
                dequeue();
                break;
            
            case 3:
                display();
                break;

            case 4:
                printf("\n Program exited");
                break;

            default:
                printf("\n Invalid choice");

        }
        

    } while(choice!=4);



    return 0;
}