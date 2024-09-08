#include <stdio.h>

void reverseArray(int *arr, int size);
void bubbleSort(int *arr, int size);

int main(){

    int size;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("These are the elements:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    reverseArray(arr, size);

    printf("\n\nThese are the reversed elements:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, size);
    printf("\n\nThese are the sorted elements:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void reverseArray(int *arr, int size){
    int i;
    int temp;

    for(i = 0; i < size/2; i++){
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void bubbleSort(int *arr, int size){
    int i, j;
    int temp;

    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Originally reverse array ni babi pero nag add rako ug bubble sort 