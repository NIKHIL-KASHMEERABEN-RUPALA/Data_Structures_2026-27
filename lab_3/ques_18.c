#include<stdio.h>

int main(){

    int n,sum=0;
    float avg = 0;

    printf("\n Enter the value of n :       ");
    scanf("%d",&n);

    for(int i = 0 ; i<=n ; i++){
        sum+=i;
    }

    avg = (float) sum/n;

    printf("\n The result is :  %f  ",avg);


    return 0;
}