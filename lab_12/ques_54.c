#include<stdio.h>

void do_sorting(int *arr , int n){
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = i+1 ; j<n ;j++){
            if( *(arr+j) < *(arr+i)){

                int temp = *(arr+j);
                *(arr+j) = *(arr+i);
                *(arr+i) = temp;

            }
        }
    }


}


int main(){

    int arr[100];

    int n;
    printf("Enter the number of elemetns :      ");
    scanf("%d",&n);

    printf("Start entering the elements :       ");

    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    do_sorting(arr,n);


    for(int k = 0 ; k<n ; k++){
        printf(" %d ",*(arr+k));
    }


    return 0;
}