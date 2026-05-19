#include<stdio.h>
#include<stdbool.h>

int main(){

    int size,to_search;
    
    printf("\n Enter total number of elements :     ");
    scanf("%d",&size);

    int arr[size];

    printf("\n Start entering the array elements ------- \n\n");

    for(int i = 0 ; i<size ; i++){
        scanf("%d",&arr[i]);
    }


    printf("\n Enter the element to search :        ");
    scanf("%d",&to_search);
    bool found = false;

    for(int i = 0 ; i<size ; i++){

        if(arr[i]==to_search){
            printf("\n desired element is present at index :    %d  ",i+1);
            found = true;
            break;
        }

        

    }

    if(found==false){
        printf("\n THe element was not found ");
    }


    return 0;
}