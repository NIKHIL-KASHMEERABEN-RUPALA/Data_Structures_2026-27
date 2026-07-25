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


char pop(){
    if(top==-1){
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

int precedence(char ch){
    if (ch=='^'){
        return 3;
    }

    else if(ch=='*' || ch =='/' || ch=='%'){
        return 2;
    }

    else if(ch=='+' || ch=='-'){
        return 1;
    }

    else{
        return 0;
    }
}





int main(){

    char infix[max], postfix[max];

    printf("\n Enter the infix expression :    ");
    scanf("%s",infix);
    int j = 0;


    for(int i = 0 ; infix[i]!='\0' ; i++){
        char ch = infix[i];

        if(isalnum(ch)){
            postfix[j++] = ch;
        }
    }


    return 0;
}