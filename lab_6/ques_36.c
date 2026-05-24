#include<stdio.h>
#include<stdbool.h>
#define size 20
#include<string.h>

char stack[size];
int top = -1;




void push(char element){
    if(top==-1){
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
    scanf("%s",&input);

    int count_a = 0 , count_b = 0 , i=0;

    while(input[i]!='b' && input[i]!='\0'){
        count_a++;
        push(input[i]);
        i++;
    }
    if(input[i]=='\0'){
        printf("\n Invaliid pattern entered ");
        return;
    }

    while(input[i]!='\0'){
        count_b++;
        i++;
    }

    return(count_a==count_b);
    
}