// Viết chương trình nhập vào các giá trị cho mảng sao cho
// mỗi phần tử chỉ chứa tối đa 2 chữ số
// hiển thị kết quả sau khi nhập

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập mảng
void fillArray(int* a, int n);
// hàm hiển thị mảng
void showArray(const int* a, int n);

int main() {
	int n;
	int a[100];
	puts("Nhap n: ");
	scanf("%d", &n);
	if (n > 0) {
		fillArray(a, n);
		puts("Cac phan tu trong mang:");
		showArray(a, n);
	}
	else {
		puts("Nhap n > 0");
	}

	return 0;
}

void fillArray(int* a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%2d", &a[i]);
	}
}

void showArray(const int* a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}