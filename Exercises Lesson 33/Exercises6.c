// Viết chương trình thực hiện các chức năng sau:
// nhập n phần tử của mảng
// hiển thị mảng ra màn hình
// nhập thêm x và tìm số lần xuất hiện của x trong mảng

#include <stdio.h>
#include <stdlib.h> // nhớ include thư viện này vào

/*
* @author Branium Academy
*/

// hàm nhập các phần tử mảng
void fillElements(int* a, const int n);
// hàm tìm số lần xuất hiện của x trong mảng
int countX(const int* const arr, const int n, const int x);

int main() {
	int n; // số phần tử của mảng
	int* arr; // con trỏ a
	puts("Nhap so duong n: ");
	scanf("%d", &n);
	if (n > 0) {
		arr = (int*)malloc(n * sizeof(int)); // cấp phát động
		fillElements(arr, n);
		// gọi hàm tìm số lần xuất hiện của x
		int x;
		puts("Nhap x: ");
		scanf("%d", &x);
		int count = countX(arr, n, x);
		printf("So lan xuat hien cua %d: %d\n", x, count);
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

int countX(const int* const p, const int n, const int x) {
	int count = 0;
	int i;
	// tìm max dùng con trỏ
	for (i = 0; i < n; i++) {
		if (*(p + i) == x) {
			count++;
		}
	}
	return count;
}
