#include<stdio.h>
#include<stdbool.h>

int main(){

    int number;

    printf("\n Enter the number to check :          ");
    scanf("%d",&number);
    bool flag = true;
    for(int i = 2 ; i<=number/2; i++){
        
        if(number%i==0){
            printf("\n The number is not prime");
            flag = false;
            break;
        }else{
            continue;
        }
    }

    if(flag){
        printf("\n The number is prime");
    }


    return 0;
}