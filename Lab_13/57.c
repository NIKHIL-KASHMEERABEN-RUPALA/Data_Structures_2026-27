

#include <stdio.h>

#define MAX 100      // Stack ni maximum capacity set kari chhe

// Global Array ane TOP variable nu declaration, je stack ni andar elements store karva mate use thase
int stack[MAX];
int top = -1;

// Stack ni andar element insert karva mate push function
void push()
{
    int value;

    // Base Guard / Error Check: Jo stack aakho bharai gayo hoy toh overflow thashe
    if (top == MAX - 1)
    {
        printf("\nStack Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("Enter value to PUSH: ");
    scanf("%d", &value);

    // Index ne badhavo ane value ne top position par assign karo
    top++;
    stack[top] = value;

    printf("%d inserted successfully.\n", value);
}

// Stack mathi top element delete karva mate pop function
void pop()
{
    // Base Guard / Error Check: Jo stack pehle thi j khali hoy toh underflow thashe
    if (top == -1)
    {
        printf("\nStack Underflow! Stack is empty.\n");
        return;
    }

    // Top position par rahelo element delete thashe ane pointer ek step niche utarse
    printf("%d deleted successfully.\n", stack[top]);
    top--;
}

// Stack na badha elements ne screen par show karva mate display function
void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is Empty.\n");
        return;
    }

    printf("\nStack Elements (Top -> Bottom):\n");

    // LIFO logic pramaney iteration hammeša top thi chalai ne 0 index sudhi lese
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

// Stack ni vachhe mathi koi pan specific position no element jova mate peep function
void peep()
{
    int position, index;

    if (top == -1)
    {
        printf("\nStack is Empty.\n");
        return;
    }

    printf("Enter position from TOP: ");
    scanf("%d", &position);

    // Relational top input position ne array index ma convert karva mate formula
    index = top - position + 1;

    // Validation Check: Array boundaries out of bounds na thavi joie
    if (index < 0 || index > top)
    {
        printf("Invalid Position.\n");
        return;
    }

    printf("Element at position %d is %d\n", position, stack[index]);
}

// Stack na koi pan existing element ni value badalva mate change function
void change()
{
    int position, value, index;

    if (top == -1)
    {
        printf("\nStack is Empty.\n");
        return;
    }

    printf("Enter position from TOP: ");
    scanf("%d", &position);

    // Input data validation mate mapping formula calculate karo
    index = top - position + 1;

    if (index < 0 || index > top)
    {
        printf("Invalid Position.\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    // Selected array index memory space par navi value update karo
    stack[index] = value;

    printf("Element updated successfully.\n");
}

int main()
{
    int choice;

    // User interaction mate do-while infinite structure loop banavi chhe
    do
    {
        printf("\n==============================");
        printf("\n      STACK USING ARRAY");
        printf("\n==============================");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. PEEP");
        printf("\n5. CHANGE");
        printf("\n6. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peep();
                break;

            case 5:
                change();
                break;

            case 6:
                printf("\nProgram Ended.\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 6);

    return 0;
}