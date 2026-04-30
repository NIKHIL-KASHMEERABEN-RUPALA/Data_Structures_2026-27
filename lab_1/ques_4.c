#include<stdio.h>

int main(){

    int num1, num2 , num3;

    
        printf("enter value of the first number:      ");
        scanf("%d",&num1);


        printf("enter value of the second number:      ");
        scanf("%d",&num2);


        printf("enter value of the third number:      ");
        scanf("%d",&num3);


        if(num1>num2 && num1>num3){
            printf("%d is largest -- first number is largest",num1);
        }

        if(num2>num1 && num2>num3){
            printf("%d is largest -- second number is largest",num2);
        }


        if(num3>num1 && num3>num2){
            printf("%d is largest -- third number is largest",num3);
        }


    return 0;
}