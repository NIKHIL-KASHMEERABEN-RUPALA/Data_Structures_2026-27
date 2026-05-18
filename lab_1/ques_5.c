#include<stdio.h>
#include<stdbool.h>

bool isLeapYear(int year){
   return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int main(){

    int year;

    printf("\n Enter the year :     ");
    scanf("%d",&year);

    if(isLeapYear(year)){
        printf("\n %d is a leap year",year);
    }
    else{
        printf("\n %d is not a leap year",year);
    }


    return 0;
}