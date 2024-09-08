#include <stdio.h>

int sort(int *arr, int size);
float getMedian(int *arr, int size);
int findMax(int *arr, int size);
void reverseArray(int arr[], int size);

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

    printf("\nThe elements of the array:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    sort(arr, size);

    printf("\n\nThe sorted array: ");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    reverseArray(arr, size);
    printf("\nThe reversed array of the sorted array:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    
    float result = getMedian(arr, size);
    printf("\nThe median of the sorted array is %.2f", result);

    int getMax = findMax(arr, size);
    printf("\nThe maximum value is: %d", getMax);

    return 0;
}

int sort(int *arr, int size){
    int i, j, temp;

    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return temp;
}

float getMedian(int *arr, int size){
    int i;

    if(size % 2 == 0){
        return (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
    }else{
        return arr[size / 2];
    }
}

int findMax(int *arr, int size){
    int i;
    int max = arr[0];

    for(i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

void reverseArray(int arr[], int size){
    int i;
    int temp;

    for(i = 0; i < size / 2; i++){
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i -1] = temp;
    }
}

//APPLIED DATA STRUCT