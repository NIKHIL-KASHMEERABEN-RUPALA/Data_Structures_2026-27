#include<stdio.h>
#include<stdbool.h>

// bubble sort ---> best case is O(n)
// worst case is O(n^2)

// we can use optimization that if no element is swapped then it means that 
// array is already sorted and no swapping has taken place 

void bubbleSort(int arr[] , int size){
    int i,j,temp;
    bool swapped ;    

    for(i=0 ; i<size-1 ; i++){
        swapped = false;

        for(j = i+1 ; j<size-i-1 ; j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }

        if(swapped==false){
            printf("\n The array is already sorted ");
            break;
        }

    }

}