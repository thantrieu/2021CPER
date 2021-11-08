// @author: braniumacademy
// @version: 2021.11
// @see: https://braniumacademy.net

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n, k;
        scanf("%d%d", &n, &k);
        if(n < 0 || k > n) {
            puts("NO RESULT");
        } else {
            for (int j = k; j <= n; j++) {
                if(j % 2 == 1) {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}
