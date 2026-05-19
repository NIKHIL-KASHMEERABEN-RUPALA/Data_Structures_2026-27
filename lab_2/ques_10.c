#include<stdio.h>

void toPalindrome(int number){
    int reverse = 0;
    while(number>0){
        int digit = number%10;
        reverse = reverse*10+digit;
        number/=10;
    }
    printf("\n The result is %d ",reverse);
}


int main(){

    int input;
    printf("\n Enter the number :       ");
    scanf("%d",&input);

    toPalindrome(input);



    return 0;
}