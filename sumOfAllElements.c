#include <stdio.h>

double getSum(double array[], int size);
int main(){
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    double array[size];
    int i;

    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++){
        scanf("%lf", &array[i]);
    }

    double sum = getSum(array, size);

    printf("Sum of all elements in the array: %.2f\n", sum);

    return 0;
}

double getSum(double array[], int size){
    double sum = 0;
    int i;

    for(i = 0; i < size; i++){
        sum += array[i];
    }

    return sum;
}

//SUM OF ALL ELEMENTS