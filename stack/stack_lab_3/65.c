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
 

int F(char symbol){

    if(symbol == '('){
        return 9;
    }
    
    else if(isalnum(symbol)){
        return 7;
    }

    else if(symbol=='^'){
        return 6;
    }

    else if(symbol=='*' || symbol =='/' || symbol=='%'){
        return 3;
    }
    
    else if(symbol=='+' || symbol=='-'){
        return 1;
    }

    else if(symbol==')'){
        return 0;
    }   

}


int G(char symbol){
    if (isalnum(symbol)){
        return 8;
    }
    else if(symbol=='^'){
        return 5;
    }
    else if(symbol=='*' || symbol=='/' || symbol=='%'){
        return 4;
    }
    else if(symbol == '+' || symbol =='-'){
        return 2;
    }

    else if(symbol=='('){
        return 0;
    }
    else if(symbol==')'){
        return -1;
    }
}


int R(char symbol){
    if(isalnum(symbol)){
        return 1;

    }

    else if(symbol == '+' || symbol == '-' ||
        symbol == '*' || symbol == '/' ||
        symbol == '^'){
            return -1;
        }

    return 0;
}

