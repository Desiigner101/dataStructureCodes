#include <stdio.h>
#include <string.h>

void reverseString(char *str);

int main(){

    int i;
    char str[100];

    printf("Enter a string to be reversed: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    reverseString(str);
    printf("\nThe reversed string is: %s", str);

    return 0;
}

void reverseString(char *str){

    int length = strlen(str);
    int i;
    char temp;

    for(i = 0; i < length / 2; i++){
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

//REVERSE STRING