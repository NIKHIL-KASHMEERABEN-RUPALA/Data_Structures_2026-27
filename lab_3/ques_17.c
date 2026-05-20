#include<stdio.h>

int main(){

    int m,n,sum=0;

    printf("\n Enter the value of m:        ");
    scanf("%d",&m);

    printf("\n Enter the value of n:        ");
    scanf("%d",&n);


    for(int i = m ; i<=n ; i++){
        sum+=i;
    }

    printf("\n The result is :    %d      ",sum);


    return 0;
}