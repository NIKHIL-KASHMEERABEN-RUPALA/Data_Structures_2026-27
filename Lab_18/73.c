#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

// Front end thi element insert karva mate function
void insertFront(int x)
{
    // Overflow Check: Circular queue property validation
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }
    

    // Pehlo element insert thaye tyaare banne pointers 0 par set karo
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    // Circular wrap-around mate logic: front array na end par shift thashe
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = x;
    printf("%d inserted at Front successfully.\n", x);
}

// Rear end thi element insert karva mate function
void insertRear(int x)
{
    // Overflow Check
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    // Initial insertion state
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
    printf("%d inserted at Rear successfully.\n", x);
}

// Front end thi element delete karva mate function
int deleteFront()
{
    // Underflow Check
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return -1;
    }

    int data = deque[front];

    // Jo ek j element vadhyo hoy ane delete thay toh resets pointers
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("%d deleted from Front.\n", data);
    return data;
}

// Rear end thi element delete karva mate function
int deleteRear()
{
    // Underflow Check
    if (rear == -1)
    {
        printf("Deque Underflow\n");
        return -1;
    }

    int data = deque[rear];

    // Single element deletion reset
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    // Circular wrap-around condition
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }

    printf("%d deleted from Rear.\n", data);
    return data;
}

// Circular Array traversal display logic
void display()
{
    if (front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque Elements: ");
    int i = front;

    // Circular iteration traverse logic
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, x;

    do
    {
        printf("\n----- DOUBLE ENDED QUEUE -----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &x);
            insertFront(x);
            break;

        case 2:
            printf("Enter Value: ");
            scanf("%d", &x);
            insertRear(x);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Program Ended\n");
            break;

        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 6);

    return 0;
}