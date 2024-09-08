#include <stdio.h>
#include <stdlib.h>  // For malloc, realloc, and free

void addNewElement(int **arr, int *size, int newElement, int index);

int main() {
    int size, i, newElement, index;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the new element to add: ");
    scanf("%d", &newElement);

    printf("Enter the index (0 to %d) where you want to add the element: ", size);
    scanf("%d", &index);

    if (index < 0 || index > size) {
        printf("Invalid index.\n");
        free(arr);  // Free allocated memory before returning
        return 1;
    }

    // Add the new element
    addNewElement(&arr, &size, newElement, index);

    printf("\nUpdated array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}

void addNewElement(int **arr, int *size, int newElement, int index) {
    int i;

    // Reallocate memory to increase the size by 1
    *arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));

    if (*arr == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    // Shift elements to the right starting from the end to make space for the new element
    for (i = *size; i > index; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    // Insert the new element at the specified index
    (*arr)[index] = newElement;

    // Increment the size of the array
    (*size)++;
}
