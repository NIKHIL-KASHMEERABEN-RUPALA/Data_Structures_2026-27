#include<stdio.h>
#include<string.h>
#define max 20

char stack[max];
int isVowel(char ch){
    return (ch=='a' || ch=='A' || ch=='e' || ch == 'E' || ch=='I' || ch=='i' || ch=='o' || ch=='O' || ch == 'u' || ch == 'U');
}


int main(){

    int T , N;
    char string[max];


    printf("\n Enter total test cases :       ");
    scanf("%d",&T);

    while(T--){

        printf("\n Enter value of N :     ");
        scanf("%d",&N);


        printf("\n Enter string :      ");
        scanf("%s",string);

        for(int i = 0 ; i < N ; i++){
            if(isVowel(string[i])){
                int top = -1;
                for(int j = 0 ; j < i ; j++){
                    stack[++top] = string[i];
                }

                for(int j = 0 ; j<i ; j++){
                    string[j] = stack[top--];
                }
            }
            
        }

    }



    



    return 0;
}