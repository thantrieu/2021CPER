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
        if(n < 0) {
            puts("NO RESULT");
        } else {
            for (int j = 0; j <= n; j++) {
                if(j % 2 == 0) {
                    printf("%d ", j);
                }
            }
        }
    }
    printf("\n");
}
