#include<stdio.h>

int main(){

    int n;
    printf("\n  Enter the value of n:       ");
    scanf("%d",&n);

    int sum = 0 ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j>0 ; j--){
            sum+=j;
        }
    }

    printf("%d \n",sum);


    return 0;
}