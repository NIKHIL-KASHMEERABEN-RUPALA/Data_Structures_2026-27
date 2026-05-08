// Write a program to read and display n numbers using an array.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){

    int n;

    printf("\n Enter the size :         ");
    scanf("%d",&n);

    int arr[n];

    printf("\n Start entering the numbers :     ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }

    for(int j = 0 ; j < n ;j++){
        printf(" %d ",arr[j]);
    }



    return 0;
}