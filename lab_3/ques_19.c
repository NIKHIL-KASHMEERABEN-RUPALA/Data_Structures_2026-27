#include<stdio.h>

int main(){

    int n , smallest , largest , pos_smallest=1 , pos_largest=1;

    printf("\n Enter total inputs :     ");
    scanf("%d",&n);

    int arr[n];

    printf("\n Start entering the numbers :     ");

    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    smallest = arr[0];
    largest = arr[0];

    for(int j = 1 ; j<n ; j++){
        if(arr[j]>largest){
            largest = arr[j];
            pos_largest = j+1;
        }
        else if(arr[j]<smallest){
            smallest = arr[j];
            pos_smallest = j+1;
        }
    }

    printf("\n %d is largest  and is present at index %d   ,   %d is smallest and is present at index %d ",largest,pos_largest,smallest,pos_smallest);



    return 0;
}