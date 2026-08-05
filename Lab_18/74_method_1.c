#include <stdio.h>

#define MAX 10

// Global parallel arrays ane size tracker declaration
int data[MAX];      
int priority[MAX];  
int size = 0;      

// Priority basis par element enqueue (insert) karva mate nu function
void enqueue(int val, int prio)
{
    // Base Guard / Overflow Check: Jo queue full hoy toh error display karo
    if (size == MAX)
    {
        printf("Priority Queue Overflow! Cannot insert (%d, Priority: %d)\n", val, prio);
        return;
    }

    // High priority value ne aagad rakhva mate nana priority vala elements ne right shift karo
    int i = size - 1;
    while (i >= 0 && priority[i] < prio)
    {
        priority[i + 1] = priority[i]; // Priority array ne right shift karo
        data[i + 1] = data[i];         // Matching data ne pan right shift karo
        i--;
    }

    // Perfect sorted position (i + 1) par new val ane prio store karo
    priority[i + 1] = prio;
    data[i + 1] = val;
    size++;

    printf("Inserted: Value = %d | Priority = %d\n", val, prio);
}

// Highest priority element delete karva mate nu dequeue function
void dequeue()
{
    // Base Guard / Underflow Check: Jo queue khali hoy toh code return karo
    if (size == 0)
    {
        printf("Priority Queue Underflow!\n");
        return;
    }

    // Array descending order ma hovathi index 0 par hammesha highest priority element hase
    printf("Deleted: Value = %d (Priority = %d)\n", data[0], priority[0]);

    // Index 0 no element remove thaya pachi baaki na badha elements ne left side shift karo
    for (int i = 0; i < size - 1; i++)
    {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}

// Queue na badha parallel elements ne format ma display karva mate nu function
void display()
{
    if (size == 0)
    {
        printf("Priority Queue is Empty.\n");
        return;
    }

    printf("\n--- Parallel Arrays Priority Queue ---\n");
    printf("Index | Value | Priority\n");
    printf("------------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("  %d   |  %-4d |    %d\n", i, data[i], priority[i]);
    }
    printf("------------------------\n");
}

int main()
{
    int choice, val, prio;

    // Interactive user menu loop
    while (1)
    {
        printf("\n----- Parallel Arrays Priority Queue Menu -----\n");
        printf("1. Enqueue (Value + Priority)\n");
        printf("2. Dequeue (Highest Priority)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &val);
            printf("Enter Priority: ");
            scanf("%d", &prio);
            enqueue(val, prio);
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