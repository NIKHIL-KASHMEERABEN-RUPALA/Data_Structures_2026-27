#include<stdio.h>

int main(){

    int number;
    
    printf("\n Enter the number :       ");
    scanf("%d",&number);

    printf("\n The factors of the number are -------");

    for(int i = 1; i<=number/2 ; i++){
        if(number%i==0){
            printf("\n %d",i);
        }else{
            continue;
        }
    }
    printf("\n %d \n",number);



    return 0;
}