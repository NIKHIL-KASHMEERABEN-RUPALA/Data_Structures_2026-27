// WAP to print prime numbers between given interval.

// #include<stdio.h>
// #include<stdbool.h>

// bool isPrime(int number){

//     for(int i = 2 ; i < number ; i++){
//         if(number%i==0){
//             return false;
//         }
//     }
    
//     return true;

// }


// void primeDisplay(int start, int stop){

//     for(int i = start ; i <=stop ; i++){
//         if(isPrime(i)){
//             printf(" %d ",i);
//         }
//         else{
//             continue;
//         }
//     }

// }

// int main(){

//     int start , stop;

//     printf("\n  Enter the starting point :      ");
//     scanf("%d",&start);

//     printf("\n Entering the stop point :        ");
//     scanf("%d",&stop);

//     primeDisplay(start,stop);



//     return 0;
// }



#include<stdio.h>
#include<stdbool.h>

bool isPrime(int number){

    int flag = true;

    for(int i = 2 ; i<number/2 ; i++){
        if(number%i==0){
            flag=false;
            break;
        }
    }

    return flag;

}


void displayPrime(int start, int end){
    for(int i = start ; i <= end ; i++){
    if(isPrime(i)){
        printf("\n %d \n",i);
    }
}
}

int main(){

    int start , end;

    printf("\n Enter the starting range :       ");
    scanf("%d",&start);

    printf("\n Enter the ending range :     ");
    scanf("%d",&end);

    displayPrime(start,end);


    return 0;
}