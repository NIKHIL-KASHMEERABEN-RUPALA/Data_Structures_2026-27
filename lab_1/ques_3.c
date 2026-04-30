#include<stdio.h>
#include<ctype.h> // to use the tolower() fucntion

int main(){

    char x;
    printf("Enter the character to check :          ");
    scanf("%c",&x);

    char hey = tolower(x);

    switch(hey){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("\n This is a vowel ! \n");
            break;

        default:
            if(x>'a' && x<'z' || x>'A' && x<'Z'){
                printf("\n This is a consonant ! \n");
            }
            else{
                printf("\n This is a number \n");
            }
    }


    return 0;
}