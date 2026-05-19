#include<stdio.h>




int factorial(int number){
    if(number==0 || number==1){
        return 1;
    }
    return number*factorial(number-1);
}


int main(){


    int input;
    printf("\n Enter the number :       ");
    scanf("%d",&input);

    int result = factorial(input);

    printf("\n The factorial using recurssion is :   %d    ",result);

    int using_loop=1;
    for(int i = input ; i>0 ; i--){
        using_loop*=i;
    }

    printf("\n The factorial using loop is :    %d      ",using_loop);



    return 0;
}