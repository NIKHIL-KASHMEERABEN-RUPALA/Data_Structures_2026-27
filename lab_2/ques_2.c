// WAP to find power of a number using loop.
// #include<stdio.h>

// int main(){

//     int power , number ;
//     printf("Enter the number :      ");
//     scanf("%d",&number);

//     printf("Enter the power :       ");
//     scanf("%d",&power);

//     int temp = power;

//     int final_number=1;

//     while(temp>0){
//         final_number*=number;
//         temp--;
//     }

//     printf("The result is :         %d      ",final_number);


//     return 0;
// }



#include<stdio.h>
#include<math.h>

int main(){

    int base , number ;

    printf("\n Enter the number :       ");
    scanf("%d",&number);

    printf("\n Enter the power to do :      ");
    scanf("%d",&base);

    int product= 1;

    for(int i = 0 ; i < base ; i++){

        product *= number;
        
    }

    printf(" The result is %d \n",product);

    return 0;
}