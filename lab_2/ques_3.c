// WAP to reverse a number.
// #include<stdio.h>

// int main(){

//     int number;
//     printf("Enter the number :      ");
//     scanf("%d",&number);

//     int reverse_number;
    

//     while(number>0){
//         int digit = 1;
//         digit = number%10;
//         reverse_number = reverse_number*10+digit;
//         number = number/10;
//     }

//     printf("The reversed number is :    %d  ",reverse_number);

//     return 0;
// }


#include<stdio.h>
#include<stdbool.h>


int palindromeConverter(int number){
    int reverse = 0;
    int temp = number;
    
    while(temp>0){
        int digit = temp%10;
        reverse = reverse*10+digit;
        temp = temp/10;
    }

    return(reverse);
}

int main(){


    int number ;
    
    printf("Enter a number to reverse ;           ");
    scanf("%d",&number);

    int result = palindromeConverter(number);

    printf(" %d is the reversed number ",result);


    

    return 0;
}