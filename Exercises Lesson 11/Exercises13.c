#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n <= 0) {
            printf("Test %d:\nINVALID\n", i);
        } else {
            printf("Test %d:\n", i);
            for (int j = 1; j <= (int)sqrt(n); j++) {
                if(n % j == 0) {
                    printf("%d ", j);
                }
            }
            for (int j = (int)sqrt(n); j >= 1; j--) {
                if(n % j == 0 && (n / j) != j) {
                    printf("%d ", n / j);
                }
            }
            printf("\n");
        }
    }
    printf("\n");
    
    return 0;
}
