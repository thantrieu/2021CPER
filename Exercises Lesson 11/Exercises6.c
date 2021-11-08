#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n >= 1 && n <= 20) {
            unsigned long long sum = 0;
            unsigned long long factorial = 1;
            for (int j = 1; j <= n; j++) {
                factorial *= j;
                sum += factorial;
            }
            printf("Test %d:\n%llu\n", i, sum);
        } else {
            printf("Test %d:\nINVALID", i);
        }
    }
    puts("");
    
    return 0;
}
