#include <stdio.h>

int main()
{
    int arr[100], n, *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    printf("\nArray elements are:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    return 0;
}