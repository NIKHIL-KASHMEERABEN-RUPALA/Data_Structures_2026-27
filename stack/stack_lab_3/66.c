#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100

char stack[max];
int top = -1;


void push(char element){
    if(top==max-1){
        printf("\n Overflow !");
        return;
    }
    stack[++top] = element;
}



char pop(){
    if(top==-1){
        printf("\n Underflow ! ");
        return '\0';
    }
    return stack[top--];
}




char peek(){
    if(top==-1){
        return '\0';
    }
    return stack[top];
}

void reverse(char str[]){
    
    for(int i = 0 , j = strlen(str)-1 ; i<j ; i++,j--){
        char temp = str[i];
    }
}


int main(){




    return 0;
}