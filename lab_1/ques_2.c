#include<stdio.h>

int main(){

    int number;

    printf("\n Enter the number to check :      ");
    scanf("%d",&number);

    if(number%2==0){
        printf("\n Te number is even ");
    }
    else{
        printf("\n The number is odd ");
    }

    


    return 0;
}