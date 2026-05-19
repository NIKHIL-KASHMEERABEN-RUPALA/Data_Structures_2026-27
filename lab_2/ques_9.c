#include<stdio.h>

int main(){

    int power,number,result=1;

    printf("\n Enter the number :           ");
    scanf("%d",&number);

    printf("\n Enter the power :        ");
    scanf("%d",&power);

    for(int i = power ; i>0 ; i--){
        result*=number;
    }

    printf("\n the power using loop is :     %d   ",result);


    return 0;
}