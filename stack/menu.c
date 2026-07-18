#include<stdio.h>
#define max 10
int stack[max];
int top = -1;

void push(){
    if(top==max-1){
        printf("Stack overflow ! ");
        return;
    }
    printf("\n Enter the element to be pushed ! ");
    int element;
    scanf("%d",&element);
    stack[++top] = element;
}

void pop(){
    if(top==-1){
        printf("\n Stack underflow ! ");
        return;
    }
    printf("%d is the popped element ",stack[top--]);
}

void display(){
    if(top==-1){
        printf("\n THe entire stack is empty !");
        return;
    }
    
    for(int i = top ; i>=0 ; i--){
        printf(" %d ",stack[i]);
    }
}

void peep(){
    int position;
    printf("\n Enter the position to be peeped from top :     ");
    scanf("%d",&position);

    int index = top - position + 1;
    if(index<0 || index > top){
        printf("\n Invalid position");
    }
    printf("\n THe element from the top at position %d is ----- %d ",stack[index]);
}


void change(){
    int position;
    printf("\n Enter the position to be changed from top :     ");
    scanf("%d",&position);

    int index = top - position + 1;
    if(index<0 || index > top){
        printf("\n Invalid position");
    }

    int new_element;

    printf("\n Enter the value of new element :      ");
    scanf("%d",&new_element);

    stack[index] = new_element;

    printf("\n The value is updated successfully ! ");

}



int main()
{
    int choice;

    do
    {
        printf("\n      STACK USING ARRAY");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. PEEP");
        printf("\n5. CHANGE");
        printf("\n6. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peep();
                break;

            case 5:
                change();
                break;

            case 6:
                printf("\nProgram Ended.\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 6);

    return 0;
}