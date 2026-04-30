#include<stdio.h>
#include<stdbool.h>

bool isPrimeCheck(int number){

    bool flag = true;

    for(int i = 2; i<number ; i++){
        if(number%i==0){
            flag = false;
            break;
        }
    }

    return flag;


}

int main(){

    int n;
    printf("Enter the number :  ");
    scanf("%d",&n);

    if(isPrimeCheck(n)){
        printf("\n This is a prime number \n");
    }else{
        printf("\n This is not a prime number \n");
    }

    return 0;
}