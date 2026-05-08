#include <stdio.h>
#include <stdbool.h>

int main() {
    int size;
    printf("\n Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];
    bool foundDuplicate = false;

    printf(" Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                foundDuplicate = true;
                printf("\n Duplicate found: %d", arr[i]);
                
                break; 
            }
        }
        if (foundDuplicate) break; 
    }

    if (!foundDuplicate) {
        printf("\n No duplicates found.");
    }

    printf("\n");
    return 0;
}