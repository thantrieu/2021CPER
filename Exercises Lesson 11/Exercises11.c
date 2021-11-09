#include <stdio.h>

// j = 123, product = 1
// j = 12, product = 3
// j = 1, product = 6
// j = 0, product = 6

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n < 0) {
            printf("Test %d:\nINVALID\n", i);
        } else {
            long product = 1;
            for (int j = n; j > 0; j /= 10) {
                product *= j % 10;
            }
            printf("Test %d:\n%ld\n", i, product);
        }
    }
    puts("");
    return 0;
}
