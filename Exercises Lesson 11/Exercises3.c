// @author: braniumacademy
// @version: 2021.11
// @see: https://braniumacademy.net

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n <= 0) {
            printf("Test %d:\nINVALID\n", i);
        } else {
            long sum = 0;
            for (int j = 1; j <= n; j++) {
                sum += j;
            }
            printf("Test %d:\n%ld\n", i, sum);
        }
    }
    printf("\n");
    return 0;
}
