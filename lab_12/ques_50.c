// WAP to Allocate and De-allocate Memory for int, char, and float Variable at Runtime

#include<stdio.h>
#include<stdlib.h>

int main(){

    int *intPtr;
    char *charPtr;
    float *floatPtr;

    intPtr = (int *)malloc(sizeof(int));
    charPtr = (char *)malloc(sizeof(char));
    floatPtr = (float *)malloc(sizeof(float));

    printf("\n Enter an integer :       ");
    scanf("%d",intPtr);

    printf("\n Enter a float number :   ");
    scanf("%f",floatPtr);

    printf("\n Enter a character :      ");
    scanf("%c",charPtr);


    printf("\n Integer is :     %d      ",*intPtr);
    printf("\n Float number is :     %f   ",*floatPtr);
    printf("\n Character is :    %c   ",*charPtr);




    return 0;
}