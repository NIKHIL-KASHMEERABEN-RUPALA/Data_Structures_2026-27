#include<stdio.h>
#include<stdlib.h>

int main(){

    int *intptr;
    char *charptr;
    float *floatptr;

    intptr = (int *)malloc(sizeof(int));
    charptr = (char *)malloc(sizeof(char));
    floatptr = (float *)malloc(sizeof(float));

    if(intptr == NULL || charptr == NULL || floatptr == NULL){
        printf("\n Dynamic memory allocaiton has failed \n ");
        return 1;
    }

    *intptr=69;
    *charptr='a';
    *floatptr=9.45;

    printf("\n    int ptr = %d    \n",*intptr);
    printf("\n    float ptr = %f    \n",*floatptr);
    printf("\n    char ptr = %c    \n",*charptr);



    return 0;
}