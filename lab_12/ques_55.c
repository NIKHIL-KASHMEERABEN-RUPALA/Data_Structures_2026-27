#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char *start, *end;
    int palindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    start = str;
    end = str + strlen(str) - 1;

    while(start < end)
    {
        if(*start != *end)
        {
            palindrome = 0;
            break;
        }

        start++;
        end--;
    }

    if(palindrome)
        printf("Palindrome String");
    else
        printf("Not a Palindrome String");

    return 0;
}