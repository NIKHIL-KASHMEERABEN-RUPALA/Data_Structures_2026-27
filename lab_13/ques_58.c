#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;


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


void insertFront(int value){
    struct node *newNode = createNode(value);
    if(newNode == NULL) return;
    
    newNode->next = head;
    head = newNode;
    printf("\n✓ Node %d inserted at the beginning successfully.\n", value);
}


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


void deleteEnd(){
    if(head == NULL){
        printf("\n The list is already empty!\n");
        return;
    }
    
  
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


void deletePosition(int pos){
    if(head == NULL){
        printf("\n The list is already empty!\n");
        return;
    }
    
    if(pos < 1){
        printf("\nInvalid position! Position must be >= 1.\n");
        return;
    }
    
   
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


int main(){
    int choice, value, position;
    
   
    printf("  SINGLY LINKED LIST PROGRAM  \n");
   
    
    do {
       
        printf("│        MAIN MENU           │\n");
  
        printf(" 1. Insert at beginning   \n");
        printf(" 2. Insert at end         \n");
        printf(" 3. Delete from beginning \n");
        printf(" 4. Delete from end       \n");
        printf(" 5. Delete at position    \n");
        printf(" 6. Count total nodes     \n");
        printf(" 7. Display list          \n");
        printf(" 8. Exit                  \n");
       
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
                printf("\n Program terminated ");
                break;
                
            default:
                printf("\n Invalid choice! Please enter a number between 1-8.\n");
        }
        
    
        if(choice >= 1 && choice <= 7 && choice != 7 && head != NULL){
            display();
        }
        
    } while(choice != 8);
    
    return 0;
}