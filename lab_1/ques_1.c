#include<stdio.h>
#define pie 3.14159

int main(){

    float radius,area;

    printf("Enter the radius of circle :        ");
    scanf("%f",&radius);

    area = pie *radius*radius;

    printf("\n the area is %f \n",area);


    return 0;
}