#include<stdio.h>
#define size 20

int priority_queue[size];
int priority[size];
int rear = -1;


void insert(){
    if(rear == size - 1){
        printf("\n overflow !");
        return;
    }
    rear++;

    int element, its_prio;
    printf("\n Enter element to insert :        ");
    scanf("%d", &element);

    printf("\n Enter its priority:  ");
    scanf("%d", &its_prio);

    
    int i = rear;
    while(i > 0 && priority[i - 1] < its_prio) {
        priority_queue[i] = priority_queue[i - 1];
        priority[i] = priority[i - 1];
        i--;
    }

    
    priority_queue[i] = element;
    priority[i] = its_prio;
    
    printf("\n Element inserted successfully.");
}


void deleteElement(){

    int i;


    if(rear==-1){
        printf("\n Underflow ! ");
        return;
    }

    printf("\n The deleted element : %d , priority is : %d ",priority_queue[0],priority[0]);
    for(int i = 0 ; i <rear ; i++){
        priority[i] = priority[i+1];
        priority_queue[i] = priority_queue[i+1];
    }
    rear--;
    
}



void display(){
    if(rear==-1){
        printf("\n Queue is already empty !");
        return;
    }

    printf("\n ELements in priority queue are -------- ");

    printf("\n Element \t priority \n");

    for(int i = 0 ; i <=rear ; i++){
        printf("\n %d \t %d ",priority_queue[i],priority[i]);
    }
}



int main(){

    int choice;

    do{
        printf("\n Enter a choice :     ");
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Display");
        printf("\n 4. Exit the programme");
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
                printf("\n The programme has been terminated ! ");
                break;
            
            default:
                printf("\n Invalid choice !");

        }


    }while(choice != 4);


    return 0;
}