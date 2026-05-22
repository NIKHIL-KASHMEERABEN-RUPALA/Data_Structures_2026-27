#include<stdio.h>
#include<stdbool.h>
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



// void isPalindrome(char element[]){
//     int i = 0;

//     while(element[i]!='c' && element[i]!='\0'){
//         push(element[i]);
//         i++;
//     }

//     if(element[i]=='\0'){
//         printf("\n Not a valid pattern");
//     }

//     i++;

//     while(element[i]!='\0'){
//         char popped = pop();
//         bool isValid = true;
//         if(element[i]!=popped){
//             isValid = false;
//         }
//         if(!isValid){
//             printf("\n String is invalid !");
//             return;
//         }
//         i++;
//     }


// }



int main(){

    char reverse[50] , str[50];

    printf("\n Enter a string :     ");
    scanf("%s",str);

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