// Viết hàm kiểm tra số nguyên tố

#include <stdio.h>
#include <math.h>

/*
 * @author Branium Academy
 */

// hàm kiểm tra số nguyên tố
int isPrime(int n) {
	if (n < 2) { // mọi số nguyên < 2 không phải số ng.tố
		return 0;
	}
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) { // nếu n có ước khác 1 và chính nó
			return 0; // n không phải số nguyên tố
		}
	}
	return 1; // mặc định n là số ng.tố
}

int main() {
	// test
	int n;
	puts("Nhap n: ");
	scanf("%d", &n);

	if (isPrime(n)) {
		puts("La so nguyen to");
	}
	else {
		puts("Khong la so nguyen to");
	}

	return 0;
}
