#include <stdio.h>

int main() {
    unsigned short int n;
    
    scanf("%hu", &n);
    
    int result[50];
    int i = 0;
    while (n > 0) {
        result[i] = (int) (n % 10);
        i++;
        n /= 10;
    }
    
	int len = i - 1;
    i = len;
    
    while (i >= 0) {
        printf("%hu\n", result[i]);
        i--;
    }
    
    return 0;
}
