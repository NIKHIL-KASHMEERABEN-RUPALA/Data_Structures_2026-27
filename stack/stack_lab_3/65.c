#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100

char S[max];
int top = -1;

void push(char item){
    if(top>=max-1){
        printf("\n Overflow ! ");
        return;
    }
    S[++top] = item;
}

char pop(){
    if(top==-1){
        printf("\n underflow ! ");
        return '\0';
    }
    return S[top--];
}

char peep(){
    if(top==-1){
        printf("\n underflow ! ");
        return '\0';
    }
    return S[top];
}

