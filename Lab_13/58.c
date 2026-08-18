#include <stdio.h>
#include <stdlib.h>

// Stack Node mate struct nu declaration (Structure Definition)
struct Node
{
    int data;
    struct Node *next;
};

// Stack no head pointer jene apde top kesu (Initially NULL)
struct Node *top = NULL;

// Stack ni andar element add karva mate push function
void push()
{
    struct Node *newNode;

    // Runtime par nava node mate memory allocate karo (Heap space allocation)
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Base Guard: Jo system memory full hoy toh malloc NULL return kare, jene Stack Overflow kehvay
    if (newNode == NULL)
    {
        printf("\nStack Overflow! Memory not available.\n");
        return;
    }

    printf("Enter value to PUSH: ");
    scanf("%d", &newNode->data);

    // Nava node na next ne current top par point karavo
    newNode->next = top;

    // Top pointer ne update kari ne nava node par mukो
    top = newNode;

    printf("%d inserted successfully.\n", newNode->data);
}

// Stack mathi top node delete karva mate pop function
void pop()
{
    struct Node *temp;

    // Base Guard: Jo top NULL hoy eno arth k stack pehle thi j khali chhe (Underflow)
    if (top == NULL)
    {
        printf("\nStack Underflow! Stack is Empty.\n");
        return;
    }

    // Temp pointer ne delete karva vala top node par set karo
    temp = top;

    printf("%d deleted successfully.\n", top->data);

    // Top pointer ne ek step aagad badhavo (next node par)
    top = top->next;

    // Memory leak bachavva mate temp node ni allocated memory ne free karo
    free(temp);
}

// Stack na badha nodes ne top thi bottom print karva mate display function
void display()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("\nStack is Empty.\n");
        return;
    }

    printf("\nStack Elements (Top -> Bottom):\n");

    temp = top;

    // Jya sudhi list no end (NULL) na aave tya sudhi loop chalse
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next; // Next node par jao
    }
}

// Stack ni vachhe mathi koi pan position no element jova mate peep function
void peep()
{
    int position, i;
    struct Node *temp;

    if (top == NULL)
    {
        printf("\nStack is Empty.\n");
        return;
    }

    printf("Enter position from TOP: ");
    scanf("%d", &position);

    temp = top;

    // Linked List ma direct indexing na thai etle loop thi specified position par traverse karo
    for (i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // Jo loop chhelle pohanchi jay ane node NULL male toh invalid position chhe
    if (temp == NULL)
    {
        printf("Invalid Position.\n");
        return;
    }

    printf("Element at position %d is %d\n", position, temp->data);
}

// Stack na koi pan existing element ni value badalva mate change function
void change()
{
    int position, value, i;
    struct Node *temp;

    if (top == NULL)
    {
        printf("\nStack is Empty.\n");
        return;
    }

    printf("Enter position from TOP: ");
    scanf("%d", &position);

    temp = top;

    // Linear sequential traversal thi value shodho
    for (i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid Position.\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    // Maleda node no data modify karo
    temp->data = value;

    printf("Element updated successfully.\n");
}

int main()
{
    int choice;

    // User driven menu block
    do
    {
        printf("\n==============================");
        printf("\n STACK USING LINKED LIST");
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
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}