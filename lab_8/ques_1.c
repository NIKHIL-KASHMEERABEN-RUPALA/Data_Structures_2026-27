#include<stdio.h>
#define MAX 5
#include<stdlib.h>

int top = -1;
int stack[MAX];

void push(int element){
    if(top<MAX-1){
        stack[++top] = element;
    }
    else{
        printf("Overflow condition is there !");
    }
}

int pop(){
    if(top<0){
        printf("underflow condition arised ! ");
        exit(1);
    }
    return stack[top--];
}


void peep(int i){
    if(top-i+1<0){
        printf("underflow condition arised ! ");
        exit(1);
    }
    else{
        printf("The top element is %d ",stack[top-i+1]);
    }
}


void display()
{
    if(top==-1){
        printf("The stack is empty !");
        exit(1);
    }

    else{
    for(int i = top ; i>=0 ; i--){
        printf("%d",stack[i]);
    }
    printf("\n");
        }
}

void change(int element , int i){
    if(top-i+1 < 0){
        printf("invalid position !");
        exit(1);
    }

    else{
        stack[top-i+1] = element;
        printf("Element was changed succeffully !");
    }
}



int main(){
    
    int choice ;

    do{
        
        printf("Enter choice from following operations : ----");
        printf("1. push");
        printf("2. pop");
        printf("3. peep");
        printf("4. display");
        printf("5. change");
        printf("6. exit");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                int element;
                printf("Enter element to insert");
                scanf("%d",&element);
                push(element);
                break;

            case 2:
                pop();
                break;


            case 3:
                int position;
                printf("Enter position (from top):  ");
                scanf("%d",&position);
                peep(position);
                break;

            case 4:
                display();
                break;
            
            
            case 5:
                int pos , new_ele;
                printf("Enter position (from top) to change :  ");
                scanf("%d",&pos);
                printf("Enter new element :     ");
                scanf("%d",&new_ele);
                change(new_ele,pos);
                break;

            case 6:
                printf("programme terminated !");
                break;


            default:
                printf("Enter valid choice !");
                break;

        }



    } while(choice!=6);
    
    
    
    
    return 0;
}