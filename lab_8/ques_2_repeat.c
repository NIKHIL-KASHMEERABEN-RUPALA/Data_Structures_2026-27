// How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a program to solve the above problem.

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 20

int top = -1;

char stack[MAX];

void push(char element){
    if(top>=MAX-1){
        printf("\n Overflow condition arised ! \n");
        return;
    }
    else{
        stack[++top] = element;
    }
}

char pop(){
    if(top<0){
        printf("\n underflow contdition has been arised ! \n ");
        return '\0';
    }
    else{
        return stack[top--];
    }
}


bool isPalindrome(char arr[]){
    int length = strlen(arr);
    int i = 0 ;

    while(arr[i]!='c'){
        push(arr[i]);
        i++;
    }
    i++;
    while(arr[i]!='\0'){
        char popped_element = pop(arr[i]);
        if(popped_element!=arr[i]){
            break;
        }
        else{
            i++;
            continue;
        }
    }

    return(length==i);
}


int main(){

    char input[MAX];

    printf("Enter the string :          ");
    scanf("%s",input);

    if(isPalindrome(input)){
        printf("\n This is the correct pattern \n ");
    }
    else{
        printf("\n Invalid pattern found !");
    }






    return 0;
}