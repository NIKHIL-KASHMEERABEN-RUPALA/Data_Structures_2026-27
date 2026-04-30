#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX 10

char stack[MAX];
int top = -1;

void push(char x){
    if(top>MAX-1){
        printf("Overflow !");
        return;
    }
    else{
        stack[++top] = x;
    }
}

char pop(){
    if(top<0){
        printf("undeflow condition !");
        return '\0';
    }
    else{
        return stack[top--];
    }
}

bool check(char word[]){
    int total_length = strlen(word);
    int i = 0;
    while(i<total_length && word[i]=='a'){
        push(word[i]);
        i++;
    }
    while(i<total_length && word[i]=='b'){
        pop();
        i++;
    }

    if(top==-1 && i==total_length ){
        return true;
    }
    else{
        return false;
    }
}


int main(){

    char word[MAX];
    printf("Enter a string to check :   ");
    scanf("%s",word);

    if(check(word)){
        printf("Matched perfectly !");

    }
    else{
        printf("Didnt match perfectly !");
    }

    return 0;
}