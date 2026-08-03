#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack
int stack[MAX];
int top = -1;

// Push function
void push(int value)
{
    stack[++top] = value;
}

// Pop function
int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i, op1, op2, result;

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    for(i = 0; postfix[i] != '\0'; i++)
    {
        // If character is operand
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');   // Convert character to integer
        }
        else
        {
            // Pop two operands
            op2 = pop();
            op1 = pop();

            // Perform operation
            switch(postfix[i])
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;

                case '%':
                    result = op1 % op2;
                    break;

                case '^':
                    result = (int)pow(op1, op2);
                    break;

                default:
                    printf("Invalid Operator\n");
                    return 0;
            }

            // Push result back
            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}