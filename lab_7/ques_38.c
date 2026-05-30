#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;


int push(char ch)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return 0;
    }

    stack[++top] = ch;
    return 1;
}


int pop()
{
    if(top == -1)
    {
        return 0;      
    }

    top--;
    return 1;
}

int main()
{
    char str[MAX];

    printf("Enter string: ");
    scanf("%s", str);

    
    if(strlen(str) == 0)
    {
        printf("Result = \"\"\n");
        return 0;
    }

    for(int i = 0; str[i] != '\0'; i++)
    {
   
        if(str[i] != '*')
        {
            if(!push(str[i]))
            {
                return 0;     
            }
        }

       
        else
        {
            if(!pop())
            {
                printf("Invalid Input!\n");
                return 0;
            }
        }
    }

    
    stack[top + 1] = '\0';

    printf("Result = %s\n", stack);

    return 0;
}