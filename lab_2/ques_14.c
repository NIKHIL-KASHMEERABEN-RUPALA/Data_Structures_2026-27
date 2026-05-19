#include<stdio.h>
int main(){
    int n;

    printf("Enter the value of n :      ");
    scanf("%d",&n);
    int sum = 0;


    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            sum+=j;
        }
    }

    printf("The total sum of the series is: %d\n", sum);

    return 0;
}