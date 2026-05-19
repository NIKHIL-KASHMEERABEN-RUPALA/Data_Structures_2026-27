// // WAP to print Armstrong number from 1 to 1000.
// #include<stdio.h>
// #include<stdbool.h>
// #include<string.h>
// #include<math.h>


// bool isArmstrong(int number){

//     int count = 0;

//     int temp = number;

//     while(temp!=0){
//         count++;
//         temp=temp/10;
//     }


//     int digit;

//     temp = number;
//     int product_sum = 0;

//     while(temp>0){
//         digit = temp%10;
//         product_sum += pow(digit,count);
//         temp /= 10;
//     }

//     return (product_sum==number);

// }

// int main(){

//     int start,end;
//     printf("Enter the starting point :      ");
//     scanf("%d",&start);

//     printf("Enter the ending point :        ");
//     scanf("%d",&end);

//     for(int i = start ; i <= end ; i++ ){
//         if(isArmstrong(i)){
//             printf("%d",i);
//         }
//         else{
//             continue;
//         }
//     }

//     return 0;
// }




#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isArmstrong(int number){

    int total_digits = 0 ;
    int temp = number;

    while(temp>0){
        total_digits += 1;
        temp = temp/10;
    }

    int sum_product = 0;

    temp = number;
    while(temp>0){
        int digit = temp%10;
        sum_product += pow(digit,total_digits);
        temp = temp/10;
    }

    return (sum_product==number);
}


int main(){

   
    for(int i = 1 ; i<=1000 ; i++){

    if(isArmstrong(i)){
        printf("\n %d is amrstrong number \n",i);
    }
    else{
        continue;
    }
    }

    return 0;
}