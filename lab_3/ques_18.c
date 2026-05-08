// Write a program to calculate average of first n numbers.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){

    int n;

    printf("\n Enter the value of n :       ");
    scanf("%d",&n);

    float avg = 0.0;

    for(int i = 1 ; i <= n ; i++){
        avg += i;
    }

    avg = avg/n;

    printf("\n  %f is the average ",avg);

    return 0;

}