#include<stdio.h>
#define size 20

int stack[size];
int top = -1;


void push(int element){
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


int pop(){
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
    }

}


int main(){




    return 0;
}