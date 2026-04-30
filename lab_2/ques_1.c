#include<stdio.h>

int factorial(int number){
    int temp = number;
    int result=1;
    while(temp>0){
        result*=temp;
        temp--;
    }
    return result;
}

int main(){

    int n;
    printf("Enter the number :      ");
    scanf("%d",&n);

    int using_factorial = factorial(n);

    int without_factorial = 1;

    while(n>0){
        without_factorial*=n;
        n--;
    }

    printf("\n using factorial we get %d \n",using_factorial);

    printf("\n without factorial we get :   %d      \n",without_factorial);




}