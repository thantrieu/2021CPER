// Viết chương trình thực hiện các chức năng sau:
// nhập vào số nguyên dương n và n phần tử của một mảng nguyên
// kiểm tra xem mảng trên có đối xứng hay không
// tìm giá trị min, max trong mảng dùng tham chiếu
// tìm trung bình cộng các số nguyên tố trong mảng dùng tham chiếu

#include <stdio.h>
#include <math.h>

/*
* @author Branium Academy
*/

// hàm nhập n và n phần tử của mảng
void getElements(int* a, int* n);
// kiểm tra mảng có đối xứng hay không
int isReversible(const int* a, int n);
// tìm giá trị lớn nhất và nhỏ nhất
void findMinMax(const int* a, int n, int* min, int* max);
// tính trung bình cộng các số nguyên tố
void avgPrime(const int* a, int n, float* avg);

int main() {
	int n;
	int a[100];
	getElements(a, &n);
	if (n > 0) {
		// mảng đối xứng
		if (isReversible(a, n)) {
			puts("Mang doi xung");
		}
		else {
			puts("Mang khong doi xung");
		}
		// tìm min, max
		int min, max;
		findMinMax(a, n, &min, &max);
		printf("Gia tri min: %d\nGia tri max: %d\n", min, max);
		// trung bình cộng các số nguyên tố trong mảng
		float avg;
		avgPrime(a, n, &avg);
		printf("TBC cac so nguyen to trong mang: %0.2f\n", avg);
	}
	else {
		puts("Nhap n > 0");
	}

	return 0;
}

void getElements(int* a, int* n) {
	puts("Nhap so nguyen duong n: ");
	scanf("%d", n);// con trỏ không cần & trước tên biến
	int i;
	for (i = 0; i < *n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

int isReversible(const int* a, int n) {
	int i;
	for (i = 0; i <= n / 2; i++) {
		if (a[i] != a[n - 1 - i]) {
			return 0;
		}
	}
	return 1;
}

void findMinMax(const int* a, int n, int* min, int* max) {
	int i;
	*min = a[0];
	*max = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] < *min) {
			*min = a[i];
		}
		if (*max < a[i]) {
			*max = a[i];
		}
	}
}

void avgPrime(const int* a, int n, float* avg) {
	int isPrime(int n); // hàm nguyên mẫu
	int count = 0;
	int sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (isPrime(a[i])) {
			count++;
			sum += a[i];
		}
	}
	if (count > 0) {
		*avg = (float)sum / count;
	}
	else {
		*avg = 0;
	}
}

int isPrime(int n) {
	if (n < 2) {
		return 0;
	}
	int i;
	int bound = (int)sqrt(n);
	for (i = 2; i <= bound; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}