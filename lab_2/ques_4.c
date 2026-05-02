// WAP to find factors of a given number.

// #include<stdio.h>

// void findFactors(int number){

//     for(int i = 1 ; i <=number ; i++)
//     {
//         if(number%i==0){
//             printf(" %d  ",i);
//         }else{
//             continue;
//         }
        
//     }

// }

// int main(){

//     int number ;

//     printf("\n  Enter the number :     ");
//     scanf("%d",&number);

//     findFactors(number);


//     return 0;

// }


#include<stdio.h>
#include<stdbool.h>


bool isFactor(int i,int number){

    bool flag = true;
    if(number%i!=0){
        flag = false;
    }

    return flag;

}

void display_factors(int number){
    for(int i = 1 ; i<=number ; i++){
        if(isFactor(i,number)){
            printf(" %d is a factor \n",i);
        }
        else{
            continue;
        }
    }
}


int main(){

    int number;
    printf("Enter a number :        ");
    scanf("%d",&number);

    display_factors(number);



    return 0;
}