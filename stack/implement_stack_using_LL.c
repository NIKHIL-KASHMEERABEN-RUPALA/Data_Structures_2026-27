#include<stdio.h>
struct Node{
    int data;
    struct Node*next;
};

struct Node *top = NULL;

void push(){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("\n Physical Stack overflow ! system capacity reached at peak ");
        return;
    }
    printf("\n Enter the value to be pushed :     ");
    scanf("%d",&newNode->data);
    newNode->next =top;
    top = newNode;
    printf("%d inserted successfully.\n", newNode->data);
}


void pop(){
    if(top==NULL){
        printf("\n The stack is empty ! ");
        return;
    }
    struct Node*temp = top;
    printf("\n Popped value = %d ",top->data);
    top = top->next;
    free(temp);
}


void display(){
    struct Node* temp ;
    if(top==NULL){
        printf("\n Stack is empty ! ");
        return;
    }
    temp = top;
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp = temp->next;
    }
    printf("\n Entire list has been printed successfully ! ");
}

void peep(){
    if(top==-1){
        printf("Stack is already empty , so nothing to peep ! ");
        return;
    }
    struct Node*temp = top;
    printf("\n Enter the position to peep from top :        ");
    int position;
    scanf("%d",&position);
    int i = 1;
    while(i<position && temp!=NULL){
        temp = temp->next;
        i++;
    }
    if(temp==NULL){
        printf("\n Invalid position ! ");
    }
    printf("%d is the element you wanted to peep ",temp->data);
}



void change(){
    if(top==-1){
        printf("\n The stack is empty , no element are there ! ");
        return;
    }
    int pos;
    printf("\n Enter the position from top of stack :       ");
    scanf("%d",&pos);

    struct Node *temp = top;
    int i = 1;
    while(i<pos && temp!=NULL){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("\n Invalid position has been entered ! ");
        return;
    }
    int new_info;
    printf("\n Enter new data part :     ");
    scanf("%d",&new_info);
    temp->data = new_info;
}


int main()
{
    int choice;

    do
    {
       
        printf("\n STACK USING LINKED LIST");
       
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. PEEP");
        printf("\n5. CHANGE");
        printf("\n6. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peep();
                break;

            case 5:
                change();
                break;

            case 6:
                printf("\nProgram Ended.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}