#include<stdio.h>
#include<stdlib.h>

int main(){


    int arr[100];
    int n;

    printf("\n Enter total elements :       \n");
    scanf("%d",&n);

    int *intptr ;
    int largest = arr[0];
    

    intptr = (int *)malloc(sizeof(int));

    if(intptr==NULL){
        printf("\n Dynamic memory allocation has been failed \n ");
        return 1;
    }

    printf("Enter the elements of array :           \n");
    for(int i = 0 ; i < n ; i++){
        
        scanf("%d",intptr+i);
        int current = *(intptr+i);
        if(largest < current){
            largest = current;
        }
        else{
            continue;
        }
    }


    printf("\n LArgest element is :     %d  ",largest);

    

    return 0;
}