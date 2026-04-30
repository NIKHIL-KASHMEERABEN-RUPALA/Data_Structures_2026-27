#include<stdio.h>

void findFactors(int number){

    for(int i = 1 ; i <=number ; i++)
    {
        if(number%i==0){
            printf(" %d  ",i);
        }else{
            continue;
        }
        
    }

}

int main(){

    int number ;

    printf("\n  Enter the number :     ");
    scanf("%d",&number);

    findFactors(number);


    return 0;

}