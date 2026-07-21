#include<stdio.h>
#include<string.h>
#define max 100
int top=-1;

char stack[max];

void push(char element){
    if(top>=max-1){
        printf("\n Overflow condition ! ");
    }
    stack[++top] = element;
}