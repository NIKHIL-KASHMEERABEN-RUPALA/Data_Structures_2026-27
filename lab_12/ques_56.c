// WAP to define a C structure named Student (roll_no, name, branch and
// batch_no) and also to access the structure members using Pointer.

#include<stdio.h>

struct student{
    int roll_no;
    char name[30];
    char branch[30];
    int batch_no;
};


int main(){


    struct student s1;
    struct student *ptr = &s1;
    
    printf("\n Enter the roll no. of student :      \n");
    scanf("%d",&ptr->roll_no);

    printf("\n Enter the name of the student :      \n");
    scanf("%s",&ptr->name);

    printf("\n Enter the branch of the student :        \n");
    scanf("%s",&ptr->branch);

    printf("\n Enter the batch_no of the student :          \n");
    scanf("%d",&ptr->batch_no);


    printf("\n the student details are as follows :        \n");
    
    printf("\n ------------- \n");

    printf("\n The roll no. is :    %d    ",ptr->roll_no);

    printf("\n The name of the student is :     %s        \n",&ptr->name);

    printf("\n The branch of the student is :      %s      \n",ptr->branch);

    printf("\n The batch number of the student is :     %d    ",ptr->batch_no);



    return 0;
}

