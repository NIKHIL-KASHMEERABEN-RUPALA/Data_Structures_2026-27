#include<stdio.h>

int main(){

    int number;
    printf("Enter the number :      ");
    scanf("%d",&number);

    int reverse_number;
    

    while(number>0){
        int digit = 1;
        digit = number%10;
        reverse_number = reverse_number*10+digit;
        number = number/10;
    }

    printf("The reversed number is :    %d  ",reverse_number);

    return 0;
}