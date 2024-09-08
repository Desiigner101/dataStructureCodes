#include <stdio.h>

float getAverage(float *arr, int size);

int main() {
    int size;
    int i;

    printf("Enter the size: ");
    scanf("%d", &size);

    float arr[size];
    printf("Enter the elements:\n");
    for (i=0; i<size; i++){
        scanf("%f", &arr[i]);
    }

    //float ashley = getAverage(arr, size);
    printf("The average is: %.2f", getAverage(arr, size));

    return 0;
}

float getAverage(float *arr, int size) {
    int i;
    float sum = 0;
    float average = 0;
    
    for(i=0; i<size; i++) {
        sum += arr[i];
    }
 
    average = sum / size;

    return average;

}

FIND AVERAGE