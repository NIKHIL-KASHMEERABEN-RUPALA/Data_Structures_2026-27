// Write a program to calculate sum of numbers from m to n.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){

    int m,n;

    printf("\n Enter the value of m :       ");
    scanf("%d",&m);

    printf("\n Enter the value of n :       ");
    scanf("%d",&n);


    int sum = 0;

    for(int i = m ; i <=n ; i++){
        sum+=i;
    }

    printf("%d",sum);


    return 0;
}
