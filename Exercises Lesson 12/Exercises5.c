// Nhập số nguyên 0 <= n <= 23 và tính n!
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen 0 <= n <= 23: ");
	scanf("%d", &n);
	if (n < 0 || n > 23) {
		puts("Vui long nhap 0 <= n <= 23");
	}
	else {
		unsigned long long factorial = 1;
		int i = 2;
		while (i <= n) {
			factorial *= i;
			i++;
		}
		printf("%d!= %llu\n", n, factorial);
	}
}