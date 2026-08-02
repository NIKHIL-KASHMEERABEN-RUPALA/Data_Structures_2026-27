#include <stdio.h>

int queue[5];
int front = -1;
int rear = -1;

void Cenqueue(int x) {
    if ((rear + 1) % 5 == front) {
        printf("\nOverflow!\n");
        return;
    }
    rear = (rear + 1) % 5;
    queue[rear] = x;
    if (front == -1) {
        front = 0;
    }
    printf("\nInserted %d successfully.\n", x);
}

int Cdequeue() {
    if (front == -1) {
        printf("\nCqueue underflow!\n");
        return -1;
    }
    int y = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % 5;
    }
    return y;
}

void display() {
    if (front == -1) {
        printf("\nCqueue is empty!\n");
        return;
    }

    printf("\nQueue elements: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % 5;
    } while (i != rear);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                Cenqueue(value);
                break;
            case 2:
                value = Cdequeue();
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}