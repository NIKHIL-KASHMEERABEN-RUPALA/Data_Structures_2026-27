#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100

char stack[max];
int top = -1;

void push(char element){
    if(top>=max-1){
        printf("\n Overflow of stack ! ");
        return;
    }
    stack[++top] = element;
}


int main(){



    return 0;
}