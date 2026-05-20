#include<stdio.h>
#include<stdbool.h>

int main(){

    int size;
    printf("\n Enter the size of array :        ");
    scanf("%d",&size);

    int arr[size];
    
    printf("\n Start enterting the array elements :         ");
    for(int i = 0 ; i<size ;i++){
        scanf("%d",&arr[i]);
    }

    bool duplicate = false;

    for(int i = 0 ; i < size ; i++){
        for(int j = i+1 ; j < size ; j++){
            if(arr[i]==arr[j]){
                duplicate = true;
                break;
            }
            else{
                continue;
            }
        }
        if(duplicate){
            break;
        }
    }

    if(duplicate){
        printf("\n The array contains duplicate elements! \n");
    } else {
        printf("\n All elements are unique (No duplicates found). \n");
    }


    return 0;
}