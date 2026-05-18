#include<stdio.h>
#include<ctype.h>

int main(){

    char new , original;

    printf("\n Enter a character :      ");
    scanf("%c",&original);

    new = tolower(original);

    switch(original){
        case 'a':
        printf("\n This is a vowel ");
        break;

        case 'e':
        printf("\n This is a vowel ");
        break;


        case 'i':
        printf("\n This is a vowel  ");
        break;


        case 'o':
        printf("\n This is a vowel ");
        break;


        case 'u':
        printf("\n This is a vowel : u ");
        break;

        default:
        printf("\n Entered character is not vowel ");
        break;
    }

    



    return 0;
}