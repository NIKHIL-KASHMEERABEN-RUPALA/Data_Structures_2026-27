#include<stdio.h>

int main(){

    int power , number ;
    printf("Enter the number :      ");
    scanf("%d",&number);

    printf("Enter the power :       ");
    scanf("%d",&power);

    int temp = power;

    int final_number;

    while(temp>0){
        final_number = number*number;
        temp--;
    }

    printf("The result is :         %d      ",final_number);


    return 0;
}
