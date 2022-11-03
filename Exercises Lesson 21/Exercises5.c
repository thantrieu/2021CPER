// Tính tổng các chữ số của một số

#include <stdio.h>

/*
 * @author Branium Academy
 */

 //hàm nguyên mẫu tính tổng các chữ số của 1 số
int sumOfDigits(long long n);

int main() {
	// test tổng các chữ số
	long long n;
	puts("Nhap so nguyen n: ");
	scanf("%lld", &n);

	if (n < 0) {
		n = -n;
	}
	int result = sumOfDigits(n);
	printf("Sum of digits = %d\n", result);

	return 0;
}

int sumOfDigits(long long n) {
	if (n < 10) {
		return n; // trường hợp cơ sở
	}
	else { // bước đệ quy
		return n % 10 + sumOfDigits(n / 10);
	}
}