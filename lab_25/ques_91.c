#include<stdio.h>
#include<stdbool.h>

int main(){

    int size;

    printf("\n Enter the size of array :        ");
    scanf("%d",&size);

    int arr[size];

    printf("\n Enter the elements of array ------  ");
    for(int i = 0 ; i<size ; i++){
        scanf("%d",&arr[i]);
    }

    int key , low , high , mid;

    printf("\n Enter the element to search :        ");
    scanf("%d",&key);

    low = 0;
    high = size-1;
    

    bool found = false;

    while(low<=high){

        mid = (low+high)/2;

        if(key==arr[mid]){
            printf("element is present at index :   %d  ",mid+1);
            found = true;
            break;
        }
        else if(key<arr[mid]){
            high = mid-1;
        }
        else if(key>arr[mid]){
            low = mid+1;
        }
    }

    if(found==false){
        printf("\n THe element was not found !");
    }

    return 0;
}