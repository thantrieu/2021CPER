#include <stdio.h>

// 0     1234
// 4     123
// 43    12
// 432   1
// 4321  0

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n < 0) {
            n *= -1;
        }
        int reverse = 0;
        for (int j = n; j > 0; j /= 10) {
            reverse = reverse * 10 + j % 10;
        }
        if(n == reverse) {
            printf("Test %d: YES\n", i);
        } else {
            printf("Test %d: NO\n", i);
        }
    }
    return 0;
}
