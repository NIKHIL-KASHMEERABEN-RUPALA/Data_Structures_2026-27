#include<stdio.h>
#define max 10
int stack[max];
int top = -1;

void push(int element){
    if(top==max-1){
        printf("Stack overflow ! ");
        return;
    }
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

}