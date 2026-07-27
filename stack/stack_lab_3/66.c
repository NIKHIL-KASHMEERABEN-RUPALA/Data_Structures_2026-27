#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char ch)
{
    stack[++top] = ch;
}


char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

char peek()
{
    if (top == -1)
        return '\0';

    return stack[top];
}

void reverse(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void swapBracket(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
}


int precedence(char ch)
{
    switch (ch)
    {
        case '^':
            return 3;

        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}


void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}


int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter Infix Expression: ");

    scanf("%s", infix);

    reverse(infix);

    swapBracket(infix);

    infixToPostfix(infix, postfix);

    strcpy(prefix, postfix);

    reverse(prefix);

    printf("\nPrefix Expression : %s\n", prefix);

    return 0;
}