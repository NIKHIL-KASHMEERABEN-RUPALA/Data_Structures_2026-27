#include <stdio.h>

#define MAX 10

// Global single array ane size variable declaration
int pq[MAX];
int size = 0;

// Max Priority Queue ma element insert karva mate nu function (Descending Order)
void enqueue(int value)
{
    // Base Guard / Overflow Check: Jo queue aakhi bharai gai hoy toh error print karo
    if (size == MAX)
    {
        printf("Priority Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    // Max Priority Logic: Shift smaller elements to the right to place higher value at the front
    int i = size - 1;
    while (i >= 0 && pq[i] < value)
    {
        pq[i + 1] = pq[i]; // Nana elements ne right side shift karo
        i--;
    }

    // Saachi sorted position (i + 1) par new value place karo
    pq[i + 1] = value;
    size++;

    printf("%d inserted successfully into Max Priority Queue.\n", value);
}

// Highest Priority Element (Maximum Value) delete karva mate nu dequeue function
void dequeue()
{
    // Base Guard / Underflow Check: Jo size 0 hoy toh queue khali chhe
    if (size == 0)
    {
        printf("Priority Queue Underflow!\n");
        return;
    }

    // Array descending order ma hovathi index 0 par hammesha maximum element (highest priority) j hase
    printf("Deleted Max Priority Element: %d\n", pq[0]);

    // Index 0 no element remove thaya pachi baaki na badha elements ne left side shift karo
    for (int i = 0; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Priority Queue na badha elements state display karva mate nu function
void display()
{
    if (size == 0)
    {
        printf("Max Priority Queue is Empty.\n");
        return;
    }

    printf("\n--- Max Priority Queue (Descending Order) ---\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", pq[i]);
    }
    printf("\n--------------------------------------------\n");
}

int main()
{
    int choice, value;

    // Interactive user menu loop
    while (1)
    {
        printf("\n----- Max Priority Queue Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}