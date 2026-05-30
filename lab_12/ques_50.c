#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *i;
    char *c;
    float *f;

    i = (int *)malloc(sizeof(int));
    c = (char *)malloc(sizeof(char));
    f = (float *)malloc(sizeof(float));

    printf("Enter an integer: ");
    scanf("%d", i);

    printf("Enter a character: ");
    scanf(" %c", c);

    printf("Enter a float: ");
    scanf("%f", f);

    printf("\nInteger = %d", *i);
    printf("\nCharacter = %c", *c);
    printf("\nFloat = %.2f", *f);

    free(i);
    free(c);
    free(f);

    return 0;
}