#include <stdio.h>

int main(void) {
    char input;

    do {
        printf("Enter a character (Y to continue, X to exit): ");
        scanf(" %c", &input);

        if (input == 'Y' || input == 'y') printf("Continuing...\n");
        else if (input == 'X' || input == 'x') printf("Exiting...\n");
    } while (input != 'X' && input != 'x');
    
    return 0;
}