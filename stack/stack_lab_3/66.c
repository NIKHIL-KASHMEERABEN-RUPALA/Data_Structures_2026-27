#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100

char stack[max];
int top = -1;

void push(char element){
    if(top==max-1){
        printf("\n Overflow !");
        return;
    }
    stack[++top] = element;
}

char pop(){
    if(top==-1){
        printf("\n Underflow ! ");
        return '\0';
    }
    return stack[top--];
}

char peek(){
    if(top==-1){
        return '\0';
    }
    return stack[top];
}


int main(){




    return 0;
}