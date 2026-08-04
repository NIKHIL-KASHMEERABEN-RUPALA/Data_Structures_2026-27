#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack nu Declaration
char S[MAX];
int TOP = -1;


// Stack na jaruri functions
void PUSH(char item)
{
    // Jo stack aakho bharai gayo hoy toh overflow thashe
    if (TOP == MAX - 1)
    {
        printf("\nStack Overflow");
        return;
    }

    S[++TOP] = item;
}

char POP()
{
    // Jo stack khali hoy toh null aapse
    if (TOP == -1)
        return '\0';

    return S[TOP--];
}

char PEEP()
{
    // Stack ni sabthi upar ni value jova mate (kadhavya vagar)
    if (TOP == -1)
        return '\0';

    return S[TOP];
}

// Input Precedence Function (F) - Bahar thi aavta character ni priority
int F(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 3;

        case '^':
            return 6;

        case '(':
            return 9;

        case ')':
            return 0;

        default:
            // Jo aa character operand (A thi Z ke 0 thi 9) hoy toh
            if (isalnum(symbol))
                return 7;
    }

    return -1;
}


// Stack Precedence Function (G) - Stack ni andar rahela character ni priority
int G(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-':
            return 2;

        case '*':
        case '/':
            return 4;

        case '^':
            return 5;

        case '(':
            return 0;

        default:
            // Jo aa character operand hoy toh
            if (isalnum(symbol))
                return 8;
    }

    return -1;
}


// Rank Function (R) - Expression sachu chhe ke nahi te check karva mate
int R(char symbol)
{
    // Operand no rank 1 hoy
    if (isalnum(symbol))
        return 1;

    // Operator no rank minus 1 hoy
    if (symbol == '+' || symbol == '-' ||
        symbol == '*' || symbol == '/' ||
        symbol == '^')
        return -1;

    return 0;
}

// Main Program ahiya thi chalu thay chhe
int main()
{
    char INFIX[MAX];
    char POLISH[MAX];
    char NEXT;
    char TEMP;

    int RANK = 0;
    int i = 0;
    int j = 0;

    printf("Enter Infix Expression : ");
    scanf("%s", INFIX);

    // Step 1: Stack ni andar pehla '(' push karo
    PUSH('(');

    // Input expression ni chhelle ')' jodi do jethi process end thai sake
    strcat(INFIX, ")");

    // Step 2: Polish (Postfix) string ne khali (empty) karo
    POLISH[0] = '\0';

    // Step 3: Pehlo character read karo
    NEXT = INFIX[i++];

    // Step 4: Jya sudhi string puri na thay (null na aave) tya sudhi loop fershe
    while (NEXT != '\0')
    {
        // Jo aapelo symbol khotu (invalid) hoy toh loop mathi bahar aavi jao
        if (F(NEXT) == -1)
        {
            printf("\nINVALID EXPRESSION");
            return 0;
        }

        // Step 5: Jo stack ni priority input karta vadhare hoy toh pop kari ne result ma nakho
        while (TOP != -1 && G(PEEP()) > F(NEXT))
        {
            TEMP = POP();
            POLISH[j++] = TEMP;
            RANK += R(TEMP);

            // Jo rank 1 thi ocho thay toh math pramaney expression khotu chhe
            if (RANK < 1)
            {
                printf("\nINVALID EXPRESSION");
                return 0;
            }
        }

        // Jo stack vachhe thi j khali thai gayo hoy toh expression invalid chhe
        if (TOP < 0)
        {
            printf("\nINVALID EXPRESSION");
            return 0;
        }

        // Step 6: Jo banne ni precedence sarakhi na hoy toh navo character stack ma push karo
        if (G(PEEP()) != F(NEXT))
        {
            PUSH(NEXT);
        }
        else
        {
            // Jo precedence sarakhi hoy (jem ke banne brackets hoy) toh khali pop kari do
            POP();
        }

        // Step 7: Pachi no character read karo
        NEXT = INFIX[i++];
    }

    // String ne proper end karva mate null character muko
    POLISH[j] = '\0';

    // Step 8: Chhelle check karo ke rank exactly 1 chhe ke nahi ane stack khali chhe ke nahi
    if (TOP != -1 || RANK != 1)
    {
        printf("\nINVALID EXPRESSION");
    }
    else
    {
        printf("\nPostfix Expression : %s", POLISH);
    }

    return 0;

}