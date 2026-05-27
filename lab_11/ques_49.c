#include<stdio.h>
#define size 20

int priority_queue[size];
int priority[size];
int front = -1;
int rear = -1;


void insert(){
    if(rear==size-1){
        printf("\n Underflow !");
        return;
    }
    rear++;

    int i;
    
    int element , its_prio;
    printf("\n Enter element to insert :        ");
    scanf("%d",&element);

    printf("\n Enter its priority:  ");
    scanf("%d",&its_prio);

    for(i = rear ; i > 0  ; i--){

        if(its_prio > priority[i-1]){
            int temp = priority[i-1];
            priority[i-1] = its_prio;
            priority[i] = temp;

            temp = priority_queue[i-1];
            priority_queue[i-1] = element;
            priority_queue[i] = temp;

        }
        else{
            break;
        }

    }

    priority_queue[i] = element;
    priority[i] = its_prio;
    
}



void deleteElement(){

    int i;


    if(rear==-1){
        printf("\n Underflow ! ");
    }

    printf("\n The deleted element : %d , priority is : %d ",priority_queue[0],priority[0]);
    for(int i = 0 ; i <=rear ; i++){
        priority[i] = priority[i+1];
        priority_queue[i] = priority_queue[i+1];
    }
    rear--;
    
}



void display(){
    
}



int main(){




    return 0;
}