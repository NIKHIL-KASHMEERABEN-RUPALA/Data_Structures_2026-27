#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

char stack[MAX];
int top;

// Stack ni andar character insert karva mate push function (Base Guard sathe)
void push(char ch)
{
    // Base Guard: Jo input string stack capacity karta moti hoy toh overflow block thashe
    if (top >= MAX - 1)
    {
        printf("\nStack Overflow! Expression khub moti chhe.\n");
        exit(1);
    }
    stack[++top] = ch;
}

// Stack mathi character kadhava mate pop function
char pop()
{
    // Jo stack khali hoy toh extra placeholder representation character '#' return karo
    if (top == -1)
        return '#';      

    return stack[top--];
}

// String balanced chhe ke nahi te check karva nu main logic function
int isBalanced(char str[])
{
    int i;
    char ch, temp;

    top = -1;      // Darek testcase chalu thaye stack pointer ne fresh refresh karo

    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];

        // Jo incoming character Opening Bracket hoy toh stack ma push karo
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }

        // Jo incoming character Closing Bracket hoy toh stack mathi check karva pop karo
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            temp = pop();

            // Base Guard: Jo stack pehle thi j khali male, eno arth closing bracket vadhare chhe
            if (temp == '#')
                return 0;

            // MCQ Trap Check: Pop karelo opening pair ane closing bracket matching na hoy toh 0 return karo
            if ((ch == ')' && temp != '(') ||
                (ch == '}' && temp != '{') ||
                (ch == ']' && temp != '['))
            {
                return 0;
            }
        }
        else
        {
            // Base Guard: Brackets sivay no koi invalid symbol parse thay toh error declare karo
            printf("\nInvalid symbol detected in string!\n");
            return 0;
        }
    }

    // Aakhi string pati gaya pachi jo stack completely empty (-1) thaye toh j string balanced chhe
    if (top == -1)
        return 1;

    return 0;
}

int main()
{
    int T;
    char str[MAX];

    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T--)
    {
        scanf("%s", str);

        printf("%d\n", isBalanced(str));
    }

    return 0;
}