#include<stdio.h>
#define size 20

int stack[size];
int top = -1;


void push(){
    if(top == size-1){
        printf("\n Stack overflow !");
        return;
    }
    else{
        int to_insert;
        printf("\n Enter the element to insert :        ");
        scanf("%d",&to_insert);

        stack[++top] = to_insert;

        printf("\n Element inserted successfully\n");
    }
}


void pop(){
    if(top==-1){
        printf("\n Stack underflow condition !");
        return;
    }else{
        int removed = stack[top--];
        printf("\n The element %d was popped ",removed);
        
    }
}


void display(){

    int i;

    if(top==-1){
        printf("\n The stack is empty !");
    }

    else{
        printf("\n The stack elements are -----");
        for(i = size ; i>=0 ; i--){
            printf("\n %d ",stack[i]);
        }
    }


}


int peep(){
    int position ;
    if(top==-1){
        printf("\n The stack is empty ! , no element to peep ");
    }

    printf("\n Enter the position from top :        ");
    scanf("%d",&position);

    if(position<=0 || position>top+1){
        printf("\n Invalid position");
    }else{
        printf(" %d was at the top ",stack[top-position+1]);
    }

}


void change(){

    int position , new_element;
    printf("\n Enter the postition from top :       ");
    scanf("%d",&position);

    if(top==-1){
        printf("\n The stack is empty");
        return;
    }
    if(position<=0 || position>top+1){
        printf("\n Invalid position ");
    }else{
        printf("\n Enter the new element to insert :        ");
        scanf("%d",&new_element);
        stack[size-position+1] = new_element;
        printf("\n The new element was inserted successfully !  ");
    }

}


int main(){


    int choice;

    while(1){
        printf("\n Enter the choice from following :        ");
        
        printf("\n 1. Push ");
        printf("\n 2. Pop ");
        printf("\n 3. Display ");
        printf("\n 4. Peep ");
        printf("\n 5. Change ");
        printf("\n 6. Exit");

        scanf("%d",&choice);


        switch(choice){
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
                return 0;
                break;

            default:
                printf("\n Enter a valid choice ! ");
                break;

        }
        
        
    }


    return 0;
}