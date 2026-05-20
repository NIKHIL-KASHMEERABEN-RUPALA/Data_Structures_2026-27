#include<stdio.h>


int main(){

    int n;
    printf("\n Enter the size of array :        ");
    scanf("%d",&n);

    int arr[n];
    printf("\n Enter the elements of the array :        ");
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    for(int j = 0 ; j<n ; j++){
        printf(" \n %d ",arr[j]);
    }

    return 0;
}