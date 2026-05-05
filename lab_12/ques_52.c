#include<stdio.h>
#include<stdlib.h>

int main(){

    int arr[100];
    int *intptr;

    intptr = (int *)malloc(sizeof(int));

    if(intptr == NULL){
        printf("\n Dynamic memory allocation has been failed \n ");
    }

    int n;
    printf("Enter total elements :      ");
    scanf("%d",&n);

    printf("\n Enter the element --------- \n");

    for(int i = 0 ; i < n ; i++){
        scanf("%d",intptr+i);
    }

    // sum loop 
    int sum = 0 ;

    for(int j = 0 ; j<n ; j++){
        sum += *(intptr+j);
    }

    printf("\n %d is the result of sum \n",sum);


    return 0;
}