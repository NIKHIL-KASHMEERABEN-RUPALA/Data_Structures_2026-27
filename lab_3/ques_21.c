#include<stdio.h>
#include<stdbool.h>


int main(){

    int n;
    printf("\n Enter the size of array :        ");
    scanf("%d",&n);

    int arr[n];

    printf("\n Start entering the elements ------- ");
    
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }

    int firstNum , secondNum ; 

    printf("\n Enter the number to replace :        ");
    scanf("%d",&firstNum);

    printf("\n Enter the new number :       ");
    scanf("%d",&secondNum);

    bool found = false;

    for(int i = 0 ; i < n ; i++){
        if(arr[i]==firstNum){
            found = true;
            arr[i] = secondNum;
            printf("\n Encountered at position :    %d  ",i);
        }
    }

    if(!found){
        printf("\n The number was not found in the array !");
        return 1;
    }
    else{
        printf("\n The new array is -------- ");
        for(int i = 0 ; i < n ; i++){
            printf(" %d ",arr[i]);
        }
        printf("\n");
        return 0;
    }

}