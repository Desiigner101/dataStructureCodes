#include <stdio.h>

void addNewElement(int *arr, int *size, int newElement, int index);

int main(){
    int size, i, newElement, index;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size + 1];

    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the new element to add: ");
    scanf("%d", &newElement);

    printf("Enter the the index (0 to %d) where you want to add the element: ", size);
    scanf("%d", &index);

    if(index < 0 || index > size){
        printf("Invalid index..");
        return 1;
    }

    addNewElement(arr, &size, newElement, index);

    printf("\nUpdated array:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}

void addNewElement(int *arr, int *size, int newElement, int index){
    int i;

    for(i = *size; i > index; i--){
        arr[i] = arr[i - 1];
    }

    arr[index] = newElement;
    (*size)++;
}

//add element with index positioning