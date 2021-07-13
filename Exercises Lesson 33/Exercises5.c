// Viết chương trình thực hiện các chức năng sau:
// nhập n phần tử của mảng
// hiển thị mảng ra màn hình
// tìm giá trị lớn nhất trong mảng
// tìm giá trị nhỏ nhất trong mảng

#include <stdio.h>
#include <stdlib.h> // nhớ include thư viện này vào

/*
* @author Branium Academy
*/

// hàm nhập các phần tử mảng
void fillElements(int* a, const int n);
// hàm tìm giá trị lớn nhất trong mảng
int findMax(const int* const arr, const int n);
// hàm tìm giá trị nhỏ nhất trong mảng
int findMin(const int* const arr, const int n);

int main() {
	int n; // số phần tử của mảng
	int* arr; // con trỏ a
	puts("Nhap so duong n: ");
	scanf("%d", &n);
	if (n > 0) {
		arr = (int*)malloc(n * sizeof(int)); // cấp phát động
		fillElements(arr, n);
		// gọi hàm tìm min và max
		int min = findMin(arr, n);
		int max = findMax(arr, n);
		printf("Gia tri max = %d\nGia tri min = %d\n", max, min);
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

int findMax(const int* const p, const int n) {
	int max = *(p);
	int i;
	// tìm max dùng con trỏ
	for (i = 1; i < n; i++) {
		if (*(p + i) > max) {
			max = *(p + i);
		}
	}
	return max;
}

int findMin(const int* const p, const int n) {
	int min = *(p);
	int i;
	// tìm min dùng con trỏ
	for (i = 1; i < n; i++) {
		if (*(p + i) < min) {
			min = *(p + i);
		}
	}
	return min;
}