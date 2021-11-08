#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n <= 0) {
            puts("INVALID");
        } else {
            double sum = 0.0;
            for (int j = 1; j <= n; j++) {
                sum += 1.0 / (j * j);
            }
            printf("%0.5lf", sum);
        }
    }
    puts("");
    return 0;
}
