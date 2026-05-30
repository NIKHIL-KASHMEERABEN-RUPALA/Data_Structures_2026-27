#include <stdio.h>

int main()
{
    int arr[100], n, sum = 0;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    for(int i = 0; i < n; i++)
    {
        sum += *(ptr + i);
    }

    printf("Sum = %d", sum);

    return 0;
}