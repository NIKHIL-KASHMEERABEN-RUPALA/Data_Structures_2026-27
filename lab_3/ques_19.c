// Write a program to find position of the smallest number & the largest number from given n numbers.


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>





int main(){


    int smallest,largest,n;

    printf("\n Enter the value of n :       ");
    scanf("%d",&n);

    int arr[n];

    printf("\n Enter the number :       \n");
    int i;
    for( i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
        
    }

    largest = arr[0];
    smallest = arr[0];
    int pos_largest = 0;
    int pos_smallest = 0;

    for(int j = 0 ; j <n ; j++){
        if(arr[j]>largest){
            largest = arr[j];
            pos_largest = j+1;
        }
        if(arr[j]<smallest){
            smallest = arr[j];
            pos_smallest = j+1;
        }
    }

    printf("\nLargest number is %d at position %d", largest, pos_largest + 1);
    printf("\nSmallest number is %d at position %d\n", smallest, pos_smallest + 1);





    return 0;
}