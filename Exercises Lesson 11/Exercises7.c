#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n, k;
        scanf("%d%d", &n, &k);
        if(n < 0 || k <= 0) {
            printf("Test %d:\nINVALID", i);
        } else {
            printf("Test %d:\n", i);
            for (int j = k; j <= n; j++) {
                if(j % k == 0) {
                    printf("%d ", j);
                }
            }
            puts("");
        }
    }
    printf("\n");
    return 0;
}
