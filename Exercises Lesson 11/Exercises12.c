// Nhập số nguyên 0 <= n <= 93 sau đó tính
// số Fibonacci thứ n
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen n > 0: ");
	scanf("%d", &n);

	if (n < 0 || n > 93) {
		puts("Nhap so nguyen 0 <= n <= 93.");
	}
	else {
		// công thức tính số Fibonacci:
		// f0 = 0, f1 = 1
		// fn = fn-1 + fn - 2 với mọi n >= 2
		unsigned long long f0 = 0;
		unsigned long long f1 = 1;
		unsigned long long fn;
		if (n < 2) {
			fn = n;
		}
		else {
			int i;
			for (i = 2; i <= n; i++) {
				fn = f0 + f1;
				f0 = f1;
				f1 = fn;
			}
		}
		printf("So Fibonacci thu %d = %llu\n", n, fn);
	}
}