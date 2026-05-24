#include<stdio.h>
#include<stdbool.h>
#define size 20
#include<string.h>

char stack[size];
int top = -1;




void push(char element){
    if(top>=size-1){
        printf("\n Stack overflow condition !");
        return;
    }
    else{
        stack[++top] = element;
    }
}

char pop(){
    if(top<0){
        printf("\n Stack underflow condition");
        return '\0';
    }else{
        char popped = stack[top--] ;
        return popped;
    }
}


bool quesLogic(){
    char input[size];
    printf("\n Enter the string :       ");
    scanf("%s",input);

    int i=0;

    while(input[i]!='a' ){
        push(input[i]);
        i++;
    }

    if(i==0){
        return false;
    }

    

    while(input[i]=='b'){
        if(input[i]=='\0'){
            return false;
        }
        i++;
    }


    if(input[i]!='\0' && top!=-1){
        return false;
    }

    return true;
    
}