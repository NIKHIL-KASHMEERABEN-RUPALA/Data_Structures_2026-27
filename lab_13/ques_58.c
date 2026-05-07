#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

// Function to create a new node
struct node* createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("\n Dynamic memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the beginning
void insertFront(int value){
    struct node *newNode = createNode(value);
    if(newNode == NULL) return;
    
    newNode->next = head;
    head = newNode;
    printf("\n✓ Node %d inserted at the beginning successfully.\n", value);
}

// Insert node at the end
void insertEnd(int value){
    struct node *newNode = createNode(value);
    if(newNode == NULL) return;
    
    if(head == NULL){
        head = newNode;
    } else {
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\n✓ Node %d inserted at the end successfully.\n", value);
}

// Display all nodes
void display(){
    if(head == NULL){
        printf("\n The singly linked list is empty.\n");
        return;
    }
    
    printf("\n Linked List: ");
    struct node *t = head;
    while(t != NULL){
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

// Delete node from the beginning
void deleteFront(){
    if(head == NULL){
        printf("\n The list is already empty!\n");
        return;
    }
    
    struct node* temp = head;
    head = head->next;
    printf("\n✓ Deleted node %d from the beginning.\n", temp->data);
    free(temp);
}

// Delete node from the end
void deleteEnd(){
    if(head == NULL){
        printf("\n The list is already empty!\n");
        return;
    }
    
    // If only one node exists
    if(head->next == NULL){
        printf("\n✓ Deleted node %d from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    
    struct node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    printf("\n✓ Deleted node %d from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Delete node at specific position (1-indexed)
void deletePosition(int pos){
    if(head == NULL){
        printf("\n The list is already empty!\n");
        return;
    }
    
    if(pos < 1){
        printf("\nInvalid position! Position must be >= 1.\n");
        return;
    }
    
    // Deleting the first node
    if(pos == 1){
        struct node* temp = head;
        head = head->next;
        printf("\n✓ Deleted node %d from position %d.\n", temp->data, pos);
        free(temp);
        return;
    }
    
    struct node* temp = head;
    struct node* prev = NULL;
    
    for(int i = 1; i < pos; i++){
        prev = temp;
        temp = temp->next;
        if(temp == NULL){
            printf("\n Position %d is out of range!\n", pos);
            return;
        }
    }
    
    prev->next = temp->next;
    printf("\n✓ Deleted node %d from position %d.\n", temp->data, pos);
    free(temp);
}

// Count total number of nodes
void countNodes(){
    if(head == NULL){
        printf("\n Total number of nodes: 0 (List is empty)\n");
        return;
    }
    
    int count = 0;
    struct node* temp = head;
    
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    
    printf("\n Total number of nodes: %d\n", count);
}

// Main menu
int main(){
    int choice, value, position;
    
    printf("\n╔════════════════════════════════╗\n");
    printf("║   SINGLY LINKED LIST PROGRAM   ║\n");
    printf("╚════════════════════════════════╝\n");
    
    do {
        printf("\n┌────────────────────────────┐\n");
        printf("│        MAIN MENU           │\n");
        printf("├────────────────────────────┤\n");
        printf("│ 1. Insert at beginning     │\n");
        printf("│ 2. Insert at end           │\n");
        printf("│ 3. Delete from beginning   │\n");
        printf("│ 4. Delete from end         │\n");
        printf("│ 5. Delete at position      │\n");
        printf("│ 6. Count total nodes       │\n");
        printf("│ 7. Display list            │\n");
        printf("│ 8. Exit                    │\n");
        printf("└────────────────────────────┘\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertFront(value);
                break;
                
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
                
            case 3:
                deleteFront();
                break;
                
            case 4:
                deleteEnd();
                break;
                
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePosition(position);
                break;
                
            case 6:
                countNodes();
                break;
                
            case 7:
                display();
                break;
                
            case 8:
                printf("\n Program terminated. Goodbye!\n");
                break;
                
            default:
                printf("\n Invalid choice! Please enter a number between 1-8.\n");
        }
        
        // Display the list after each operation (except exit)
        if(choice >= 1 && choice <= 7 && choice != 7 && head != NULL){
            display();
        }
        
    } while(choice != 8);
    
    return 0;
}