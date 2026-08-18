#include <stdio.h>
#include <stdlib.h>

/* Singly Linked List Node nu Structural Definition (Data field ane Self-referential Pointer) */
struct Node {
    int info;
    struct Node *next;
};

/* Global Pointer References: Queue na Entry (Rear) ane Exit (Front) boundary tracking mate */
struct Node *front = NULL;
struct Node *rear = NULL;


/*
    Queue ma navo Element/Node dynamically allocate kari Rear End par Enqueue/Insert karva mate nu Function.
*/
void enqueue(int x) {

    // Dynamic Heap Memory Allocation using malloc
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    /* Memory Exhaustion Check: Heap full thaya par NULL check kari Overflow handle karo */
    if (newNode == NULL) {
        printf("\n Overflow ! Dynamic memory allocation failed.");
        return;
    }
    
    // Payload Data Initialization ane Next Pointer Termination
    newNode->info = x;
    newNode->next = NULL;

    /* Base Condition: Jo Queue completely Empty hoy, to Front ane Rear banne new node ne point karse */
    if (front == NULL) {
        front = rear = newNode;
    }
    /* Linked List Expansion: Existing Rear node na next pointer ne link kari Rear Reference update karo */
    else {
        rear->next = newNode;
        rear = newNode;
    }
}


/*
    Queue mathi Element Dequeue/Remove karva mate nu Function (FIFO - First-In-First-Out Strategy).
    Aa operation Front boundary thi Node eliminate kare che.
*/
void dequeue() {
    /* Underflow Condition: Check karo ke Linked List empty to nathi */
    if (front == NULL) {
        printf("\n Underflow ! Queue contains no elements to remove.");
        return;
    }
    
    // Deallocation mate Front Node no Temporary Reference retain karo
    struct Node *temp = front;
    printf("\n Deleted %d successfully ", temp->info);
    
    // Front pointer ne successor node par transition/advance karo
    front = front->next;
    
    /* Boundary Reset: Jo Queue no single/last node delete thayo hoy, to Rear pointer ne pan NULL set karo */
    if (front == NULL) {
        rear = NULL;
    }
    
    // Memory Leak prevent karva mate Dynamic Memory Explicitly Free/Deallocate karo
    free(temp);
}


/*
    Linked List Queue na elements ne Linear Sequential Traversal kari Console par Print karva mate nu Function.
*/
void display() {
    /* Empty State Verification */
    if (front == NULL) {
        printf("\n Queue is already empty ! ");
        return;
    }
    
    // Traversal Iterator pointer initialization Front thi
    struct Node *temp = front;
    printf("\n Queue is : \n");
    
    // Sequential Linear Traversal jya sudhi NULL terminator encounter na thay
    while (temp != NULL) {
        printf("\n %d ", temp->info);
        temp = temp->next;
    }
}


/*
    Front-most Element ne retrieve/inspect karva mate nu Function without removing the node.
*/
void peek() {
    /* State Validation Check */
    if (front == NULL) {
        printf("Queue is Empty.\n");
        return;
    }

    // Access the Payload value of the Front Node
    printf("Front Element = %d\n", front->info);
}


int main() {
    int choice, value;

    /* Interactive Menu-Driven CLI Execution Loop */
    while (1) {
        printf("\n QUEUE USING LINKED LIST \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        /* Control Flow Dispatch using Switch Statement */
        switch (choice) {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Program Ended.\n");
            return 0;

        default:
            // Input Validation Exception
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}