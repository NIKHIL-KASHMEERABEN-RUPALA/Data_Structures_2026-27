#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top;


int push(char ch)
{
    if(top == MAX - 1)   
        return 0;

    stack[++top] = ch;
    return 1;
}


char pop()
{
    if(top == -1)        
        return '\0';

    return stack[top--];
}


int isBalanced(char str[])
{
    top = -1;

    for(int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];


        if(ch == '(' || ch == '{' || ch == '[')
        {
            if(!push(ch))
                return 0;     
        }

       
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            char temp = pop();

           
            if(temp == '\0')
                return 0;

       
            if((ch == ')' && temp != '(') ||
               (ch == '}' && temp != '{') ||
               (ch == ']' && temp != '['))
            {
                return 0;
            }
        }
    }

 
    return (top == -1);
}

int main()
{
    int T;
    char str[MAX];

    scanf("%d", &T);

    while(T--)
    {
        scanf("%s", str);

        if(isBalanced(str))
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}