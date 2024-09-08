#include <stdio.h>

float findMedian(int *arr, int size);

int main(){

    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    int i;

    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the array:");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    float getMedian = findMedian(arr, size);

    printf("\nThe median of the elements is: %.2f", getMedian);

    return 0;
}

float findMedian(int *arr, int size){
    
    if(size % 2 == 0){
        return (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
    }else{
        return arr[size/2];
    }
}

//FIND MEDIAN