#include<stdio.h>
#include<math.h>
#include<stdbool.h>


bool isArmstrong(int number){
    int digits = 0, sum_product = 0;

    for(int i = number ; i>0 ; i/=10){
        digits++;
    }

    int digit =0;
    for(int j = number ; j>0 ; j/=10){
        digit = j%10;
        sum_product += pow(digit,digits);
    }


    return(sum_product==number);

}


int main(){

    int number;


    for(int i = 1 ; i<=1000 ; i++){
        
        if(isArmstrong(i)){
            printf("\n %d",i);
        }else{
            continue;
        }

    }

    return 0;
}