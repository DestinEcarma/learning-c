#include <stdio.h>

int main(void) {
    int number;

    printf("Enter your number: ");
    scanf("%d", &number);

    int counter = 1;

    while (counter <= number) {
        int y = 1;

        while (y <= number) {
            if (y == number) printf("%d ", counter + 1);
            else printf("%d ", counter);
            y++;
        }

        printf("\n");
        counter++;
    }
    
    return 0;
}