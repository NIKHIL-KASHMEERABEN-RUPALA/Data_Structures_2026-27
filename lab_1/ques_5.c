#include<stdio.h>
#include<stdbool.h>


bool isLeapYear(int year){

    if(year%4==0 && year%100!=0 || year%400==0){
        return true;
    }
    else{
        return false;
    }

}


int main(){

    int year;

    printf("Enter the year to check :       ");
    scanf("%d",&year);

    if(isLeapYear(year)){
        printf("\n Yipee , this is a leap year ! \n");
    }
    else{
        printf("\n oops this is not a leap year \n");
    }

    return 0;
}