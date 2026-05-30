#include <stdio.h>

int main()
{
    int arr[100], n, temp;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(*(ptr + j) > *(ptr + j + 1))
            {
                
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
 
    printf("\nSorted array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    return 0;
}