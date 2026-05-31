#include <stdio.h>

int main()
{
    int arr[100], n, num, pos = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to delete: ");
    scanf("%d", &num);

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == num)
        {
            pos = i;
            break;
        }
    }

    if(pos == -1)
    {
        printf("Element not found");
        return 0;
    }

    for(int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Array after deletion:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}