// WAP to check whether a number is prime or not.

// #include<stdio.h>
// #include<stdbool.h>

// bool isPrimeCheck(int number){

//     bool flag = true;

//     for(int i = 2; i<number ; i++){
//         if(number%i==0){
//             flag = false;
//             break;
//         }
//     }

//     return flag;


// }

// int main(){

//     int n;
//     printf("Enter the number :  ");
//     scanf("%d",&n);

//     if(isPrimeCheck(n)){
//         printf("\n This is a prime number \n");
//     }else{
//         printf("\n This is not a prime number \n");
//     }

//     return 0;
// }



#include<stdio.h>
#include<stdbool.h>


bool isPrime(int number){

    bool flag = true;
    for(int i = 2 ; i < number/2 ; i++){
        if(number%i==0){
            flag = false;
            break;
        }
    }

    return flag;
}

int main(){

    int number ;
    printf("Enter a number to check:            ");
    scanf("%d",&number);

    if(isPrime(number)){
        printf(" %d is prime ",number);
    }
    else{
        printf(" %d is not prime ",number);
    }





    return 0;
}