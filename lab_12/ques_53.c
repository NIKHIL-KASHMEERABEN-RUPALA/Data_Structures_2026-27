#include <stdio.h>

int main()
{
    int arr[100], n;
    int *ptr, largest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    largest = *ptr;

    for(int i = 1; i < n; i++)
    {
        if(*(ptr + i) > largest)
        {
            largest = *(ptr + i);
        }
    }

    printf("Largest element = %d", largest);

    return 0;
}