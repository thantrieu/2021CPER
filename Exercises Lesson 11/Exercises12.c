#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n < 0) {
            printf("Test %d: INVALID\n", i);
        } else if(n > 93) {
            printf("Test %d: OVERFLOW\n", i);
        } else {
            unsigned long long f0 = 0;
            unsigned long long f1 = 1;
            unsigned long long fn = n;
            for (int i = 2; i <= n; i++) {
                fn = f1 + f0;
                f0 = f1;
                f1 = fn;
            }
            printf("Test %d: %llu\n", i, fn);
        }
    }
    puts("");
    
    return 0;
}
