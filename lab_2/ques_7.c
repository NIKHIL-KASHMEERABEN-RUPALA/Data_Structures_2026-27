// WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ ...+(1+2+3+4+....+n).
// #include<stdio.h>

// int main(){

//     int n;
//     printf("\n  Enter the value of n:       ");
//     scanf("%d",&n);

//     int sum = 0 ;

//     for(int i = 1 ; i <= n ; i++){
//         for(int j = i ; j>0 ; j--){
//             sum+=j;
//         }
//     }

//     printf("%d \n",sum);


//     return 0;
// }


#include<stdio.h>

int main(){

    int user_input;

    printf("Enter a valid input ;           ");
    scanf("%d",&user_input);

    int sum = 0 ;

    for(int i = 1 ; i <= user_input ; i++){
        int j = i;
        while(j>0){
            sum += j;
            j--;
        }

    }

    printf("%d \n",sum);


    return 0;
}