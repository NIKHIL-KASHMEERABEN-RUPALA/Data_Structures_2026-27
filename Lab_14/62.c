#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

// Character stack ane top pointer ni ghoshana
char stack[MAX];
int top = -1;

// Stack ni andar character insert karva mate push function (Base Guard sathe)
void push(char ch)
{
    // Base Guard: Jo stack full thashe toh memory out-of-bounds thava thi bachavshe
    if (top >= MAX - 1)
    {
        printf("\nStack Overflow! String khub moti chhe.\n");
        exit(1);
    }
    stack[++top] = ch;
}

// Stack mathi character remove karva mate pop function (Base Guard sathe)
void pop()
{
    // Base Guard: Jo stack pehle thi empty hoy toh pop thava na de (Underflow protection)
    if (top == -1)
    {
        return;
    }
    top--;
}

int main()
{
    char str[MAX];
    int i;

    printf("Enter string: ");
    scanf("%s", str);

    // Step 1: Left-to-Right loop chalavi darek character ne process karo
    for (i = 0; str[i] != '\0'; i++)
    {
        // MCQ Logic: Jo character star '*' male toh backspace ni jem dabi baju no element udado
        if (str[i] == '*')
        {
            pop();          // Previous normal character ne stack mathi nikali do
        }
        else
        {
            // Jo normal alphanumeric character hoy toh stack ma push karo
            push(str[i]);   
        }
    }

    // Step 2: Processing patya pachi stack ma bachela final characters print karo
    printf("\nResult String: ");

    // Array order pramaney bottom thi top (0 thi top index) print thashe
    for (i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }

    printf("\n");

    return 0;
}