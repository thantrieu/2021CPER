#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n <= 0) {
            printf("Test %d: INVALID\n", i);
        } else {
            int counter = 0;
            int bound = (int)sqrt(n);
            for (int j = 1; j <= bound; j++) {
                if(n % j == 0) {
                    if((n / j) != j) {
                        counter += 2;
                    } else {
                        counter += 1;
                    }
                }
            }
            printf("Test %d: %d\n", i, counter);
        }
    }
    puts("");
    return 0;
}
