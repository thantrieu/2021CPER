// Viết chương trình thực hiện các chức năng sau:
// nhập n phần tử của mảng
// tính tổng các phần tử trong mảng

#include <stdio.h>
#include <stdlib.h> // nhớ include thư viện này vào

/*
* @author Branium Academy
*/

// hàm nhập các phần tử mảng
void fillElements(int* a, const int n);
// hàm tính tổng các phần tử
int sumElements(const int* const a, const int n);

int main() {
	int n; // số phần tử của mảng
	int* a; // con trỏ a
	puts("Nhap so duong n: ");
	scanf("%d", &n);
	if (n > 0) {
		a = (int*)malloc(n * sizeof(int)); // cấp phát động
		fillElements(a, n);
		int sum = sumElements(a, n);
		printf("Tong cac phan tu trong mang: %d\n", sum);
		free(a); // giải phóng bộ nhớ
	}
	else {
		puts("Nhap so nguyen duong n");
	}
	return 0;
}

void fillElements(int* a, const int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", a + i);
	}
}

int sumElements(const int* const a, const int n) {
	int sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum += *(a + i);
	}
	return sum; // trả về tổng
}