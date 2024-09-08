#include <stdio.h>

void multiplyBy3(int *integer);
int main(){
    int integer;

    printf("Enter an integer: ");
    scanf("%d", &integer);

    multiplyBy3(&integer);

    printf("Value after multiplying by 3: %d", integer);

}

void multiplyBy3(int *integer){
    *integer = *integer * 3;
}

//Pass by reference