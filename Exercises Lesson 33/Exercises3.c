// Viết chương trình thực hiện các chức năng sau:
// nhập n phần tử của mảng
// liệt kê các số nguyên tố trong mảng

#include <stdio.h>
#include <stdlib.h> // nhớ include thư viện này vào
#include <math.h>

/*
* @author Branium Academy
*/

// hàm nhập các phần tử mảng
void fillElements(int* a, const int n);
// hàm liệt kê các số nguyên tố trong mảng
void listedPrimes(const int* const a, const int n);
// hàm kiểm tra số nguyên tố
int isPrime(const int n);

int main() {
	int n; // số phần tử của mảng
	int* a; // con trỏ a
	puts("Nhap so duong n: ");
	scanf("%d", &n);
	if (n > 0) {
		a = (int*)malloc(n * sizeof(int)); // cấp phát động
		fillElements(a, n);
		puts("\nCac so nguyen to trong mang la: ");
		listedPrimes(a, n);
		free(a); // giải phóng bộ nhớ
	}
	else {
		puts("Nhap so nguyen duong n");
	}
	return 0;
}

int isPrime(const int n) {
	if (n < 2) {
		return 0;
	}
	int i;
	int bound = (int)sqrt(n); // lấy phần nguyên căn bậc hai
	for (i = 2; i <= bound; i++) {
		if (n % i == 0) { // nếu có ước khác 1 và chính nó
			return 0; // n không phải số nguyên tố
		}
	}
	return 1; // mặc định n là số nguyên tố
}

void fillElements(int* a, const int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", a + i);
	}
}

void listedPrimes(const int* const a, const int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (isPrime(*(a + i))) {
			printf("%d ", *(a + i));
		}
	}
}