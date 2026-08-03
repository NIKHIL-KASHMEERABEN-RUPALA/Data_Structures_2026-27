#include<stdio.h>
#include<stdlib.h>

int queue[5];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear>=5-1){
        printf("\n Queue Overflow ! ");
        return;
    }
    queue[++rear] = x;
    if(front==-1){
        front=0;
    }
}


int dequeue(){
    if(front==-1){
        printf("\n Queue underflow !");
        return -1;
    }

    int to_remove = queue[front];

    if(front==rear){
        front = rear = -1;
    }

    else{
        front = front+1;
    }
}


void display(){
    if(front==-1 || front>rear){
        printf("\n Queue is empty ! ");
        return;
    }

    for(int i = front ; i<=rear ; i++){
        printf("\n %d",queue[i]);
    }

}



int main()
{
    int choice, value;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                Enqueue(value);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }

    return 0;
}
