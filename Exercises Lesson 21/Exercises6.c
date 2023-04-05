// Tính tổng S = 1 + 1/2 + ... + 1/n

#include <stdio.h>

/*
 * @author Branium Academy
 */

 //hàm nguyên mẫu tính tổng
double sum(long n);

int main() {
	// test
	long n;
	puts("Nhap so nguyen n: ");
	scanf("%ld", &n);

	if (n > 0) {
		float s = sum(n);
		printf("%1.3f\n", s);
	}
	else {
		puts("Nhap n > 0");
	}

	return 0;
}

double sum(long n) {
	if (n == 1) {
		return n; // trường hợp cơ sở
	} // thực hiện bước đệ quy
	else {
		return (double)1 / n + sum(n - 1);
	}
}