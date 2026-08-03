#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
    char prefix[MAX];
    int i, op1, op2, result;

    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);

    // Traverse from Right to Left
    for(i = strlen(prefix) - 1; i >= 0; i--)
    {
        // If operand
        if(isdigit(prefix[i]))
        {
            push(prefix[i] - '0');
        }
        else
        {
            // Pop two operands
            op1 = pop();
            op2 = pop();

            // Perform operation
            switch(prefix[i])
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

            // Push result
            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}