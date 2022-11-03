#include <stdio.h>

// j = n = 1234
// j = 1234, sum = 0
// j = 123,  sum = 4
// j = 12,   sum = 7
// j = 1,    sum = 9
// j = 0,    sum = 10

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n < 0) {
            puts("INVALID");
        } else {
            int sum = 0;
            for (int j = n; j > 0; j = j / 10) {
                sum += j % 10;
            }
            printf("Test %d: \n%d\n", i, sum);
        }
    }
    printf("\n");
    return 0;
}
