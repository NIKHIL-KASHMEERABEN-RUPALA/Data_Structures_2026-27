#include<stdio.h>
#include<string.h>
#define max 100


char stack[max];
int top = -1;

void push(char element){
    if(top>=max-1){
        printf("\n Overflow condition ! ");
        return;
    }
    stack[++top] = element;
}


char pop(){
    if (top==-1){
        printf("\n Stack underflow condition ! ");
        return '#';
    }
    return stack[top--];
}

int main