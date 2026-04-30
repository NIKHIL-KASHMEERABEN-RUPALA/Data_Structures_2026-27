#include<stdio.h>
#define MAX 20 
#include<stdbool.h>

int top = -1;
char stack[MAX];

void push(char element){
    if(top>MAX-1){
        printf("Overflow of stack !");
        return;
    }
    stack[++top]=element;
}


char pop(){
    if(top<0){
        printf("underflow condition !");
        return '\0';
    }
    else{
        return stack[top--];
    }
}


bool isPalindromeCheck(char str[]){
    top = -1;
    int i = 0;
    while(str[i]!='c'){

        if(str[i]=='\0'){
            return false;
        }
        push(str[i]);
        i++;
    }

    i++;

    while(str[i]!='\0'){
        char temp = pop();
        if(temp!=str[i]){
            printf("This is not required series ");
            return false;
        }
        i++;
    }

    return (top==-1);
}

int main(){

    char input[MAX];

    printf("Enter the characters to be inputed :    ");
    scanf("%s",input);

    if(isPalindromeCheck(input)){
        printf("This is a perfect match");
    }
    else{
        printf("Failed match");
    }


    return 0;
}
