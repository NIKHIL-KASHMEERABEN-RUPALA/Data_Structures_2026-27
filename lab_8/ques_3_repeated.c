// Write a program to determine if an input character string is of the form aibi where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’.


#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 20

char stack[MAX];
int top = -1;




void push(char element){

    if(top>=MAX-1){
        printf("\n Overflow condition has been arised ! \n");
        return;
    }
    else{
        stack[++top] = element;
    }
}


char pop(){
    if(top<0){
        printf("\n underflow condition has been arised ! \n");
        return '\0';
    }
}





int main(){

    char input[MAX];
    printf("Enter the input character string :          ");
    scanf("%s",input);




    return 0;
}