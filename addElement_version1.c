#include <stdio.h>

void addElement(int *originalArray, int *newArray, int *size, int value);

int main(){

    int size;
    int i;
    int value;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int originalArray[size];
    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++){
        scanf("%d", &originalArray[i]);
    }

    printf("\nEnter a new value to be added: ");
    scanf("%d", &value);
    int newArray[size + 1];

    addElement(originalArray, newArray, &size, value);

    printf("The updated array:\n");
    for(i = 0; i < size; i++){
        printf("%d ", newArray[i]);
    }

    return 0;
}

void addElement(int *originalArray, int *newArray, int *size, int value){
    int i;

    for(i = 0; i < *size; i++){
        newArray[i] = originalArray[i];
    }

     newArray[*size] = value;
     (*size)++;
}

//ADD ELEMENT V1