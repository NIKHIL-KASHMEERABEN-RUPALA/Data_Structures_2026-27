#include<stdio.h>

int main(){

    int hours , minutes , seconds;

   
    printf("\n Enter the seconds :      ");
    scanf("%d",&seconds);


    hours = seconds/3600;
    minutes = (seconds - (hours*3600))/60 ; 
    int final_seconds = seconds - ((minutes*60)+(hours*3600));

    printf("\n   %d : %d : %d       \n",hours,minutes,final_seconds);
    


    return 0;
}