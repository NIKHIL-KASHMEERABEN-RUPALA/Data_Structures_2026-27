// WAP to print Armstrong number from 1 to 1000.
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>


bool isArmstrong(int number){

    char x = number;

    int length = strlen(x);

    int digit;

    int temp = number;
    int product_sum = 0;

    while(temp>0){
        digit = number%10;
        product_sum += pow(digit,length);
    }

    return (product_sum==number);

}

int main(){

    int start,end;
    printf("Enter the starting point :      ");
    scanf("%d",&start);

    printf("Enter the ending point :        ");
    scanf("%d",&end);

    for(int i = start ; i <= end ; i++ ){
        if(isArmstrong(i)){
            printf("%d",i);
        }
        else{
            continue;
        }
    }

    return 0;
}