#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n < 2) {
            printf("Test %d: NO\n", i);
        } else {
            int isPrime = 1;
            for (int j = 2; j <= (int)sqrt(n); j++) {
                if(n % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime) {
                printf("Test %d: YES\n", i);
            } else {
                printf("Test %d: NO\n", i);
            }
        }
    }
    return 0;
}
