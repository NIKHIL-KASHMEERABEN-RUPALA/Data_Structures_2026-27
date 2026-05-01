// WAP to print prime numbers between given interval.

#include<stdio.h>
#include<stdbool.h>

bool isPrime(int number){

    for(int i = 2 ; i < number ; i++){
        if(number%i==0){
            return false;
        }
    }
    
    return true;

}


void primeDisplay(int start, int stop){

    for(int i = start ; i <=stop ; i++){
        if(isPrime(i)){
            printf(" %d ",i);
        }
        else{
            continue;
        }
    }

}

int main(){

    int start , stop;

    printf("\n  Enter the starting point :      ");
    scanf("%d",&start);

    printf("\n Entering the stop point :        ");
    scanf("%d",&stop);

    primeDisplay(start,stop);



    return 0;
}
