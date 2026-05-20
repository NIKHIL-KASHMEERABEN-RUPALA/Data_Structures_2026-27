#include<stdio.h>
#include<stdbool.h>

int main(){

    int start,end;

    printf("\n Enter the starting range :       ");
    scanf("%d",&start);


    printf("\n Enter the ending range :       ");
    scanf("%d",&end);

    printf("\n The prime numbers between %d and %d are -------- \n ",start,end);

    for(int i = start ; i<=end ; i++){

        bool isPrime = true;

        if(i<=1){
            isPrime = false;
        }

        for(int j = 2 ; j*j<=i ;j++){
            if(i%j==0){
                isPrime = false;
                break;
            }
            else{
                continue;
            }
        }

        if(isPrime){
            printf("\n %d",i);
        }

    }

    return 0;
}