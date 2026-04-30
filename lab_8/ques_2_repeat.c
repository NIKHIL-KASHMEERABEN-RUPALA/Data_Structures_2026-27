#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX 20

int top=-1;
char stack[MAX];

void push(char element){
    if(top>MAX-1){
        printf("The overflow condition is being arised !");
        return;
    }
    else{
        stack[++top] = element;
    }
}

char pop(){
    if(top<0){
        printf("Underflow condition has been arised !");
        return '\0';
    }
    else{
        printf("%d",stack[top--]);
    }
}


bool isPalindromeCheck(char word[]){
    int length = strlen(word);
    int i = 0 ; 
    while(word[i]!='c'){
        push(word[i]);
        i++;
    }
    i++;
    while(word[i]!='\0'){
        char x = pop();
        if(x!=word[i]){
            printf("This is not a match");
            exit(1);
        }
        i++;
        
    }
    return (top==0 && i==length-1);
}


int main(){

    char word[MAX];
    printf("Enter the word which you want to check :        ");
    scanf("%s",word);

    if(isPalindromeCheck(word)){
        printf("perfect word series matched !");
    }
    else{
        printf("It was a failed match !");
    }

    return 0;
}