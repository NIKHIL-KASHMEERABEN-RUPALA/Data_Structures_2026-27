#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 20

int stack[MAX];
int top = -1;

void push(int element)
{
    if(top>MAX-1){
        printf("Overflow condition arised !");
        return;
    }
    else{
        stack[++top]=element;
    }
}

int pop()
{
    if(top<0){
        printf("Underflow condition arised ");
        exit(0);
    }
    else{
        return stack[top--];
    }
}



void peep(int position)
{
    if(top-position+1<0){
        printf("Invalid position to view ! ");
    }
    else{
        printf("%d is the top element !",stack[position]);
    }
}



void change(int position , int element)
{
    if(top-position+1<0){
        printf("invalid position !");
    }
    else{
        stack[position] = element;
    }
}


void display()
{
    if(top==-1){
        printf("The stack is completely empty !");
    }
    else{
        for(int i = top ; i >= 0 ; i-- ){
            printf(" %d ",stack[i]);
        }
    }
}


int main(){

    int choice ;

    do{
        printf("\n Enter the choice from the following --- \n");
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Peep \n");
        printf("4. Change \n");
        printf("5. Display \n");
        printf("6. Exit \n");
        scanf("%d",&choice);


        switch(choice){
            case 1:
                int element;
                printf("enter element :         \n");
                scanf("%d",&element);
                push(element);
                break;

            case 2:
                int y = pop();
                printf("%d",y);
                break;
            
            case 3:
                int pos;
                printf("Enter position :        ");
                scanf("%d",&pos);
                peep(pos);
                break;

            case 4:
                int position,ele;
                printf("Enter position from top to change :     ");
                scanf("%d",&position);
                printf("Enter the new element :     ");
                scanf("%d",&ele);
                change(position , ele);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("The programme has been terminated !");
                break;

            default:
                printf("Invalid choice !!");
                break;

        }
        
        
    }while(choice!=6);


    return 0;
}