// WAP to check whether the string is Palindrome or not using Pointer.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isPalindrome(char *arr , int n){
    bool flag = true;
    for(int i = 0 ; i <n/2 ; i++){
        for(int j = n ; j>=n/2 ; j--){
            if(*(arr+j)!=*(arr+i)){
                flag = false;
            }
            else{
                break;
                continue;
            }
        }
    }

    return flag;
}



int main(){

    char arr[100];

    printf("\n Enter the elements of string to check :     \n");
    scanf("%s",arr);

    int n = strlen(arr);

    bool result = isPalindrome(arr,n);

    if(result){
        printf("This is palindrome stirng !");
    }else{
        printf("Not a palindrome string ");
    }




    return 0;
}