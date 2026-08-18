#include <stdio.h>
#include <stdlib.h>

/* Static Array Allocation for Queue Data Structure */
int queue[5];

/* State tracking mate front ane rear pointers ne initially -1 (Empty State) par set karela che */
int front = -1;
int rear = -1;

/*
    Queue ma nava element ne insert/enqueue karva mate nu function.
    Aa operation Queue na Rear (pachal) end thi execute thay che.
*/
void enqueue(int x){
    /* Overflow Condition Verification: Check karo ke queue ni capacity limit cross to nathi thai */
    if(rear >= 5 - 1){
        printf("\n Queue Overflow ! Capacity Exhausted.");
        return;
    }
    
    /* Rear pointer increment karo ane new element queue ma assign karo */
    queue[++rear] = x;
    
    /* Initialization Configuration: Jo aa strictly first insertion hoy, to Front pointer ne activate karo */
    if(front == -1){
        front = 0;
    }
}


/*
    Queue mathi element remove/dequeue karva mate nu function.
    Aa operation FIFO (First-In-First-Out) architecture pramane Front (aagal) end thi thay che.
*/
int dequeue(){
    /* Underflow Condition Verification: Queue already empty che ke nahi te check karo */
    if(front == -1){
        printf("\n Queue Underflow ! No elements to remove.");
        return -1;
    }

    /* Remove thava vala element ne return karva mate temporary variable ma store karo */
    int to_remove = queue[front];

    /* 
       Reset Mechanism: Jo queue ma sirf ek j element hoto (front == rear), 
       to element remove thaya pachi pointers ne default empty state (-1) par reset karo.
    */
    if(front == rear){
        front = rear = -1;
    }
    /* Normal Execution: Pointers ne reset karvani jarur na hoy to simply Front ne aagal shift/increment karo */
    else{
        front = front + 1;
    }
    
    return to_remove;
}


/*
    Queue na currently stored elements ni sequential state print/traverse karva mate nu function.
*/
void display(){
    /* Empty State Check: Traverse karva mate array ma valid elements hova jaruri che */
    if(front == -1 || front > rear){
        printf("\n Queue is empty ! Nothing to display.");
        return;
    }

    /* Sequential Traversal: Front index thi start kari ne Rear index sudhi linear iteration karo */
    for(int i = front ; i <= rear ; i++){
        printf("\n %d", queue[i]);
    }
}


int main()
{
    int choice, value;

    /* Menu-driven CLI (Command Line Interface) implementation infinite loop sathe */
    while (1) {
        printf("\n\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* User input based operation routing using Switch Control Structure */
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);   // Function call mapping
                break;
            case 2:
                // Return value capture kari shako cho if required
                dequeue();        
                break;
            case 3:
                display();
                break;
            case 4:
                // Program execution terminate karva mate process exit routine
                exit(0);
            default:
                // Invalid input exception handling
                printf("Invalid choice! Please provide a valid operational parameter.");
        }
    }

    return 0;
}