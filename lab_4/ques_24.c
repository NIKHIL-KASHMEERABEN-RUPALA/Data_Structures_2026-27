#include <stdio.h>

int main()
{
    int arr[100];
    int n, i;
    int element, position;

    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    
    printf("Enter element to insert: ");
    scanf("%d", &element);

    
    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &position);

    
    if (position < 1 || position > n + 1)
    {
        printf("Invalid position!\n");
    }
    else
    {
        
        for (i = n; i >= position; i--)
        {
            arr[i] = arr[i - 1];
        }

        
        arr[position - 1] = element;

        n++;

        
        printf("\nArray after insertion:\n");

        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}