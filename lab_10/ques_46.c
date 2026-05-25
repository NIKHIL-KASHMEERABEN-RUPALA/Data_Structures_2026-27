#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Function to insert element
void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue Overflow! Queue is full.\n");
    }
    else
    {
        // First element insertion
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("\n%d inserted successfully.\n", value);
    }
}

// Function to delete element
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow! Queue is empty.\n");
    }
    else
    {
        printf("\nDeleted element: %d\n", queue[front]);
        front++;

        // Reset queue when empty
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

// Function to display queue
void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue elements are:\n");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
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
                printf("\nProgram exited.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}