// Viết chương trình thực hiện các chức năng sau:
// nhập n phần tử của mảng
// tính tổng các phần tử nằm trong đoạn [a, b]

#include <stdio.h>
#include <stdlib.h> // nhớ include thư viện này vào

/*
* @author Branium Academy
*/

// hàm nhập các phần tử mảng
void fillElements(int* a, const int n);
// hàm liệt kê các số nguyên tố trong mảng
int sumFromAToB(const int* const arr, const int n, const int a, const int b);

int main() {
	int n; // số phần tử của mảng
	int* arr; // con trỏ a
	puts("Nhap so duong n: ");
	scanf("%d", &n);
	if (n > 0) {
		arr = (int*)malloc(n * sizeof(int)); // cấp phát động
		fillElements(arr, n);
		int a, b;
		puts("Nhap hai so nguyen a, b: ");
		scanf("%d%d", &a, &b);
		int sum = sumFromAToB(arr, n, a, b);
		printf("Tong cac phan tu trong [%d, %d] = %d\n", a, b, sum);
		free(arr); // giải phóng bộ nhớ
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

int sumFromAToB(const int* const p, const int n, const int a, const int b) {
	int sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (*(p + i) >= a && *(p + i) <= b) {
			sum += *(p + i);
		}
	}
	return sum;
}