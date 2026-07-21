#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define max 100
int top=-1;

char stack[max];

void push(char element){
    if(top>=max-1){
        printf("\n Overflow condition ! ");
        return;
    }
    stack[++top] = element;
}

char pop(){
    if(top==-1){
        printf("\n Underflow condition ! ");
        return '#';
    }
    return stack[top--];
}


bool logic(char str[]){

}