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

        for(j = 0 ; j<size-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        if(swapped==false){
            printf("\n The array is already sorted ");
            break;
        }

    }

}


int main(){

    int size;
    printf("\n Enter the number of elements :           ");
    scanf("%d",&size);

    int arr[size];

    printf("\n Enter the array elements --------    \n");
    for(int i = 0 ; i<size ; i++){
        scanf("%d",&arr[i]);
    }

    bubbleSort(arr,size);

    for(int j = 0 ; j<size ; j++){
        printf("\n %d",arr[j]);
    }


    return 0;
}