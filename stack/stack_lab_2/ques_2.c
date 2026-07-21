#include<stdio.h>
#include<string.h>
#define max 100


char stack[max];
int top = -1;

void push(char element){
    if(top>=max-1){
        printf("\n Overflow condition ! ");
        return;
    }
    stack[++top] = element;
}



void pop(){
    if (top==-1){
        printf("\n Stack underflow condition ! ");
        return;
    }
    top = top-1;
}

int main(){

    char str[max];
    printf("\n Enter a string :    ");
    scanf("%s",str);


    for(int i = 0 ; str[i]!='\0';i++){
        if(str[i]=='*'){
            pop();
        }
        else{
            push(str[i]);
        }
    }

    return 0;
}