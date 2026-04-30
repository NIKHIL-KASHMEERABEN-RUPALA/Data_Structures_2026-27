#include<stdio.h>

int main(){

    int n;
    printf("Enter the number to check :         ");
    scanf("%d",&n);

    if(n%2==0){
        printf("\n The number is even \n");
    }
    else{
        printf("\n The number is odd \n");
    }


    return 0;
}