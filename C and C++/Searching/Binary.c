#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.size; i++)
        printf("%d ", arr.A[i]);
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.size - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    struct Array arr1;

    // Take the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &arr1.size);

    // Allocate memory for the array
    arr1.A = (int *)malloc(arr1.size * sizeof(int));

    // Input array elements
    printf("Enter %d elements:\n", arr1.size);
    for (int i = 0; i < arr1.size; i++)
        scanf("%d", &arr1.A[i]);

    // Perform binary search
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    printf("Binary Search: %d\n", BinarySearch(arr1, key));

    // Display array elements
    Display(arr1);
    
    return 0;
}
