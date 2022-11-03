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
        if(n > 0) {
            double sum = 0.0;
            for (int j = 1; j <= n; j++) {
                sum += 1.0 / j;
            }
            printf("Test %d:\n%0.3lf\n", i, sum);
        } else {
            printf("Test %d:\nINVALID\n", i);
        }
    }
    puts("");
    return 0;
}
