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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.size; i++)
    {
        if (key == arr.A[i])
        {
            swap(&arr.A[i], &arr.A[0]);
            return i; // return the found element's index
        }
    }
    return -1; // element not found
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

    // Perform Linear search
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    printf("linear Search: %d\n", LinearSearch(arr1, key));

    // Display array elements
    Display(arr1);


    return 0;
}

