#include<stdio.h>
#define MAX 20

int stack[MAX];

int top = -1;

void push(int element){
    if(top>=MAX-1){
        printf("\n stack overflow condition arised ! \n");
        return;
    }else{
        stack[++top]=element;
    }
}

int pop(){
    if(top<0){
        printf("\n Stack underflow condition \n");
        return -1;
    }else{
        return stack[top--];
    }
}

int peep(int position){
    if(top-position+1<0){
        printf("\n Invalid position ! \n");
        return -1;
    }
    else{
        return stack[top-position+1];
    }
}

void display(){
    if(top==-1){
        printf("\n Stack is empty ! \n");
    }else{
        for(int i = top ; i>=0 ; i--){
            printf(" %d ",stack[i]);
        }
    }
}

void change(int pos , int element){

    if(top-pos+1<0){
        printf("\n Invalid position ! \n");
        return;
    }else{
        stack[top-pos+1] = element;
        printf("\n Element successfully changed \n");
    }

}


int main(){

    int choice ;

    do{
        printf("Enter the choice from following ------");
        printf("\n 1. push \n");
        printf("\n 2. pop \n");
        printf("\n 3. peep \n");
        printf("\n 4. display \n");
        printf("\n 5. change \n");
        printf("\n 6. exit \n");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                int element;
                printf("Enter element to enter :        ");
                scanf("%d",&element);
                push(element);
                break;


            case 2:
                int pop_ans = pop();
                if(pop_ans != -1){
                    printf("\n popped element is :  %d ",pop_ans);
                }
                break;


            
            case 3:
                int position;
                printf("Enter position from top to be viewed :      ");
                scanf("%d",&position);
                int result_peep = peep(position);
                if(result_peep!=-1){
                    printf("\n The result is %d ",result_peep);
                }
                break;

            case 4:
                display();
                break;

            
            case 5:
                int pos , element;
                printf("Enter position to change :      ");
                scanf("%d",&pos);
                printf("Enter new element : ");
                scanf("%d",&element);
                change(pos,element);
                break;


            case 6:
                printf("\n The programme has been terminanted \n ");
                break;

            default :
                printf("\n invalid number entered \n");
                break;

        }




    }while(choice!=6);



    return 0 ;
}

