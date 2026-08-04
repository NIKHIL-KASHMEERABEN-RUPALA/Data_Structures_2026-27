#include <stdio.h>

#define MAX 10

// Global array ane size variable nu declaration
int pq[MAX];
int size = 0;

// Priority Queue ma element insert karva mate enqueue function (Sorted Insertion)
void enqueue(int value)
{
    // Base Guard / Error Check: Jo queue aakhi bharai gai hoy toh overflow thashe
    if (size == MAX)
    {
        printf("Priority Queue Overflow!\n");
        return;
    }

    // MCQ Logic: Element ne saachi priority position par mukhva mate pashal thi shift કરો
    int i = size - 1;
    while (i >= 0 && pq[i] < value)
    {
        pq[i + 1] = pq[i]; // Nana elements ne right side shift karo
        i--;
    }

    // Saachi place male tya value store karo
    pq[i + 1] = value;
    size++;

    printf("%d inserted successfully.\n", value);
}

// Highest priority element delete karva mate dequeue function
void dequeue()
{
    // Base Guard / Error Check: Jo size 0 hoy toh queue khali chhe (Underflow)
    if (size == 0)
    {
        printf("Priority Queue Underflow!\n");
        return;
    }

    // Array descending order ma chhe etle index 0 par hammesha highest priority element hase
    printf("Deleted element: %d\n", pq[0]);

    // Index 0 no element nikalya pachi baki na badha elements ne left side shift karo
    for (int i = 0; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Priority Queue na badha elements show karva display function
void display()
{
    if (size == 0)
    {
        printf("Priority Queue is Empty.\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main()
{
    int choice, value;

    // User driven menu block
    while (1)
    {
        printf("\n----- Priority Queue Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
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