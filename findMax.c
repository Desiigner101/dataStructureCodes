#include <stdio.h>

int findMax(int array[], int size);
int main(){
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    int i;

    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }

    int getMax = findMax(array, size);

    printf("The max: %d", getMax);
}

int findMax(int *array, int size){
    int max = array[0];
    int i;

    for(i = 0; i < size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }

    return max;
}

