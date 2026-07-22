#include<stdio.h>
#include<string.h>
#define max 20

char stack[max];
int isVowel(char ch){
    return (ch=='a' || ch=='A' || ch=='e' || ch == 'E' || ch=='I' || ch=='i' || ch=='o' || ch=='O' || ch == 'u' || ch == 'U');
}


int main(){

    int T , N;


    printf("\n Enter total test cases :       ");
    scanf("%d",&T);
    
    while(T--){

        printf("\n Enter value of N :     ");
        scanf("%d",&N);

    }



    return 0;
}