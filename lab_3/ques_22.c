#include<stdio.h>

int main(){

    int rows,num;

    printf("\n Enter the number of rows :       ");
    scafn("%d",&rows);

    for(int i = 0 ; i < rows ; i++){

        for(int j = 0 ; j < rows-i-1 ; j++){
            printf(" ");
        }
        num = 1;

        for(int j = 0 ; j<=i ; j++){
            printf("%d",num);
            num = ((num)*(i-j))/(j+1);
        }

        printf("\n");

    }


    return 0;
}