#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

void insertFront(int x)
{
    if (front == 0)
    {
        printf("Deque Overflow\n");
    }

    else
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }

        else
        {
            front--;
        }

        deque[front] = x;
    }
}

void insertRear(int x)
{

    if ((rear + 1) % MAX == front)
    {

        printf("Queue Overflow\n");
    }

    else
    {

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
    }
}

void deleteFront()
{
    if (front == -1)
    {

        printf("Queue Underflow\n");

        return -1;
    }

    int data = deque[front];

    if (front == rear)
    {

        front = -1;
        rear = -1;
    }

    else
    {

        front = (front + 1) % MAX;
    }

    return data;
}

void deleteRear()
{
    if (rear == -1)
    {
        printf("Deque Underflow\n");

        return -1;
    }

    int data = deque[rear];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    else
    {
        rear--;
    }

    return data;
}

// Display
void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is Empty\n");
    }

    else
    {
        printf("Deque Elements: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", deque[i]);
        }

        printf("\n");
    }
}

// Main Function
void main()
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
            return;

        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 6);
}