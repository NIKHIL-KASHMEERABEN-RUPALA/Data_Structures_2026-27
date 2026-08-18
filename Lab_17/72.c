#include <stdio.h>

/* Static Circular Buffer Array with capacity 5 */
int queue[5];

/* State tracking variables: -1 indicates empty state */
int front = -1;
int rear = -1;

/*
    Circular Queue Enqueue Function:
    Modulo arithmetic use kari ne rear boundary wrap-around kare che ane element insert kare che.
*/
void Cenqueue(int x) {
    /* 
       Overflow Condition Check:
       Modulo arithmetic thi check karo ke next rear position front index sathe collide thay che ke nahi.
    */
    if ((rear + 1) % 5 == front) {
        printf("\nOverflow! Buffer capacity exhausted.\n");
        return;
    }

    /* Rear pointer ne circularly increment karo */
    rear = (rear + 1) % 5;
    queue[rear] = x;

    /* Base Initialization: First element insert thay tyare front ne index 0 par set karo */
    if (front == -1) {
        front = 0;
    }
    printf("\nInserted %d successfully.\n", x);
}

/*
    Circular Queue Dequeue Function:
    FIFO sequence follow kari front pointer mathi element eliminate kare che.
*/
int Cdequeue() {
    /* Underflow Condition Check: Verify karo ke queue already empty to nathi */
    if (front == -1) {
        printf("\nCqueue underflow! No elements available to extract.\n");
        return -1;
    }

    /* Target element ne local variable ma preserve karo */
    int y = queue[front];

    /* 
       Reset Mechanism: 
       Jo front == rear hoy (single remaining element), to deletion pachi default empty state (-1) restore karo.
    */
    if (front == rear) {
        front = rear = -1;
    } else {
        /* Circular Shift: Front pointer ne next circular index par advance karo */
        front = (front + 1) % 5;
    }
    return y;
}

/*
    Circular Display/Traversal Function:
    Front index thi start kari circular fashion ma rear index sudhi print kare che.
*/
void display() {
    /* Empty State Verification */
    if (front == -1) {
        printf("\nCqueue is empty! Nothing to traverse.\n");
        return;
    }

    printf("\nQueue elements: ");
    int i = front;
    
    /* 
       Cyclic Traversal Loop:
       Current index print kari modulo operator thi wrap around karo jya sudhi rear reach na thay.
    */
    while (1) {
        printf(" %d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % 5;
    }
    printf("\n");
}

int main() {
    int choice, value;

    /* Interactive Menu-Driven CLI Loop */
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* Control Dispatch using Switch-Case Structure */
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
                /* Exception Handling for invalid inputs */
                printf("\nInvalid choice! Please provide a valid option.\n");
        }
    }

    return 0;
}