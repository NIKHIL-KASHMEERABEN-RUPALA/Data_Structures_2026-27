#include<stdio.h>
#include<stdlib.h>

int main(){

    int arr[100];
    int *intptr = arr;

    intptr = (int *)malloc(sizeof(int));

    if(intptr == NULL){
        printf("\n Dynamic mem. alloc. failed ! \n");
        return 1;
    }

    printf("\n Enter the array elements \n");
    for(int i = 0 ; i<100 ; i++){
        scanf("%d",intptr+2);
    }

    printf("\n The array elements are --- \n");
    for(int j = 0 ; j < 100 ; j++){
        printf("%d",intptr+j);
    }

    


    return 0;
}