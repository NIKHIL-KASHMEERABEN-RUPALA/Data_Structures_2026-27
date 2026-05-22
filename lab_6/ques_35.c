#include<stdio.h>
#include<string.h>
#define size 20

char stack[size];
int top = -1;

void push(char element){
    if(top>=size-1){
        printf("\n Stack overflow !");
        return;
    }else{
        stack[++top]= element;
        return;
    }
}

char pop(){
    if(top==-1){
        printf("\n Stack underflow ! ");
        return '\0';
    }
    else{
        char removed_element = stack[top--];
        return removed_element;
    }
}

int main(){

    char reverse[50] , str[50];

    printf("\n Enter a string :     ");
    scanf("%s",&str);

    int length = strlen(str)-1;

    for(int i = 0 ; i<strlen(str) ; i++){
        push(str[i]);
    }

    for(int j = 0 ; j<=length ; j++){
        reverse[j] = pop();
    }

    reverse[length+1] = '\0';

    if(strcmp(reverse,str)==0){
        printf("\nString is Palindrome");
    }
    else{
        printf("\nString is Not Palindrome");
    }


    


    return 0;
}