#include <stdio.h>

int main()
{
    int arr[100], n, num, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to insert: ");
    scanf("%d", &num);

    for(pos = 0; pos < n; pos++)
    {
        if(arr[pos] > num)
            break;
    }   

    for(int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = num;
    n++;

    printf("Array after insertion:\n");
 
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}