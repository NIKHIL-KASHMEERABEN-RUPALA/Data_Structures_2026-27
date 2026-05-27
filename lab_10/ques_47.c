#include<stdio.h>
#define size 20

int cqueue[size];
int front = -1;
int rear = -1;

void insert(){
    if((front==0 && rear == size-1) || (front==rear+1)){
        printf("\n Circular queue overflow condition ! ");
        return;
    }

    int element;
    printf("\n Enter the element to insert :        ");
    scanf("%d",&element);


    if(front==-1){
        front = rear = 0;
    }
    else if(rear==size-1){
        rear = 0;
    }
    else{
        rear++;
    }

    
    cqueue[rear] = element;

    printf("\n The element was inserted successfully ");


}


void deleteElement(){

    if(front==-1){
        printf("\n Queue underflow condition ! ");
        return;
    }

    printf("\n Element %d was deleted successfully ! ",cqueue[front]);

    if(front==rear){
        front = rear = -1;
    }

    else if(front==size-1){
        front = 0;
    }

    else{
        front++;
    }
}


void display(){

    if(front==-1){
        printf("\n The circular queue is already empty ! ");
        return;
    }

    printf("\n Cricular queue elements are ------");

    if(front<=rear){

    for(int i = front ; i<=rear ; i++){
        printf("%d",cqueue[i]);
    }

    }

    else{
        
        for(int i = front ; i<size ; i++){
            printf(" %d ",cqueue[i]);
        }
        for(int j = 0 ; j<=rear ; j++){
            printf(" %d ",cqueue[j]);
        }

    }
    

}



int main(){


    int choice , value;

    do{
        printf("\n Enter a choice :         ");
        printf("\n 1. Cenqueue ");
        printf("\n 2. Cdequeue ");
        printf("\n 3. Display ");
        printf("\n 4. Exit the programme ");
        scanf("%d",&choice);


        switch(choice){
            case 1:
                insert();
                break;

            case 2:
                deleteElement();
                break;
            
            case 3:
                display();
                break;

            case 4:
                printf("\n Programme terminated ! ");
                break;

            default:
                printf("\n Invalid choice ! ");

        }


    } while(choice!=4);




    return 0;
}





