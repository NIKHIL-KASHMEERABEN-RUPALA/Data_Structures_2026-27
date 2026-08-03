#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

// Evaluation stack ane top variable nu declaration
int stack[MAX];
int top = -1;

// Stack ma value umerava mate push function (Base condition sathe)
void push(int value)
{
    // Jo stack full hoy toh push na thay, program bandh thai jay
    if (top >= MAX - 1)
    {
        printf("\nStack Overflow! Expression khub moti chhe.\n");
        exit(1);
    }
    stack[++top] = value;
}

// Stack mathi value kadhava mate pop function (Base condition sathe)
int pop()
{
    // Jo stack khali hoy ane pop karie toh error aave (Operands ghate chhe)
    if (top == -1)
    {
        printf("\nINVALID EXPRESSION: Operands ni kami chhe!\n");
        exit(1);
    }
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i, op1, op2, result;

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    // Step 1: Postfix expression evaluation mate hammeša Left thi Right scan karvu pade
    for(i = 0; postfix[i] != '\0'; i++)
    {
        // Jo character number (digit) hoy toh
        if(isdigit(postfix[i]))
        {
            // ASCII value mathi actual integer value melavva mate '0' minus karo ane push karo
            push(postfix[i] - '0');
        }
        else
        {
            // Jo operator aave toh stack mathi be (2) values kadho
            // LIFO rule na lidhe pehli pop value 'op2' (right) banshe ane biji pop value 'op1' (left) banshe
            op2 = pop();
            op1 = pop();

            // Operator pramaney calculate karo
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
                    // Base Condition: Division by zero math ma shakya nathi
                    if (op2 == 0)
                    {
                        printf("\nRuntime Error: Zero (0) thi divide na thai sake!\n");
                        return 1;
                    }
                    result = op1 / op2;
                    break;

                case '%':
                    // Base Condition: Modulo by zero math ma shakay nathi
                    if (op2 == 0)
                    {
                        printf("\nRuntime Error: Zero (0) thi modulo na thai sake!\n");
                        return 1;
                    }
                    result = op1 % op2;
                    break;

                case '^':
                    // pow function double return kare chhe etle integer ma convert (typecast) karyu
                    result = (int)pow(op1, op2);
                    break;

                default:
                    printf("Invalid Operator Encountered\n");
                    return 1;
            }

            // Aavela result ne pacho stack ma muko jethi aagad evaluation chalya kare
            push(result);
        }
    }

    // Base Condition Checklist: Jo aakhi loop patya pachi stack ma barabar ek j element na bache toh expression khoti chhe
    if (top != 0)
    {
        printf("\nINVALID EXPRESSION: Extra operands bachi gaya chhe!\n");
        return 1;
    }

    // Loop puri thaya pachi chhello bachelo final answer print karo
    printf("Result = %d\n", pop());

    return 0;
}