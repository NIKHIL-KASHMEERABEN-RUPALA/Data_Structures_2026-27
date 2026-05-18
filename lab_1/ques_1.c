#include<stdio.h>
#define pie 3.14
#include<math.h>

int main(){

    float radius , area;

    printf("\n Enter the radius of circle :        ");
    scanf("%f",&radius);

    area = pie*pow(radius,2);

    printf("\n The area is :    %f    ",area);


    return 0;
}