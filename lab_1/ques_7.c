#include<stdio.h>

int main(){

    int days , weeks , year , final_days ;

    printf("Enter days :        ");
    scanf("%d",&days);


    year = days/365;
    weeks = (days - (year*365))/7;
    final_days = (days - ((year*365)+(weeks*7)));

    printf("\n      %d year :  %d weeks :  %d days          \n",year,weeks,final_days);



    return 0;
}