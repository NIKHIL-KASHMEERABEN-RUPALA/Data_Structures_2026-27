// factorial of a number
// #include<stdio.h>

// int factorial(int number){
//     if(number==0 || number==1){
//         return 1;
//     }
//     else{
//         return number*factorial(number-1);
//     }
// }

// int main(){

//     int n;
//     printf("Enter the number :      ");
//     scanf("%d",&n);

//     int using_factorial = factorial(n);

//     int without_factorial = 1;

//     while(n>0){
//         without_factorial*=n;
//         n--;
//     }

//     printf("\n using factorial we get %d \n",using_factorial);

//     printf("\n without factorial we get :   %d      \n",without_factorial);




// }



#include<stdio.h>

int factorial(int number){
    int temp = number;
    if(temp == 0 || temp==1){
        return 1;
    }
    else{
        return temp*factorial(temp-1);
    }
}

int main(){

    int number;
    printf("Enter a number :        ");
    scanf("%d",&number);

    int x = factorial(number);

    printf("\n %d \n",x);

    return 0;
}