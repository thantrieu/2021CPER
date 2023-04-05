// Viết chương trình sử dụng con trỏ hàm thực hiện các chức năng sau:
// sắp xếp tăng dần
// sắp xếp giảm dần
// cho phép người dùng chọn cách thức sắp xếp từ bàn phím
// hiện kết quả ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập các phần tử mảng
void getElements(int* a, int n);
// hàm hiển thị các phần tử mảng
void showArray(int* a, int n);
// hàm sắp xếp
void sort(int* a, int n, int(*compare)(int x, int y));
// hàm sắp xếp tăng
int greater(int a, int b);
// hàm sắp xếp giảm
int smaller(int a, int b);

int main() {
	int a[100];
	int n;
	puts("Nhap n: ");
	scanf("%d", &n);
	if (n > 0) {
		getElements(a, n);
		// khai báo con trỏ hàm
		int (*compare)(int, int) = NULL;
		int choice;
		printf("Chon cac sap xep:\n1. Tang dan.\n2. Giam dan.\nBan chon? ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			// sắp xếp theo thứ tự tăng dần
			compare = greater;
			break;
		case 2:
			// sắp xếp theo thứ tự giảm dần
			compare = smaller;
			break;
		default:
			puts("Nhap dung tuy chon 1 hoac 2.");
			break;
		}
		if (compare != NULL) {
			sort(a, n, compare);
			puts("Mang sau sap xep: ");
			showArray(a, n);
		}
	}
	else {
		puts("Nhap n > 0");
	}
	return 0;
}

void getElements(int* a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void showArray(int* a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

void sort(int* a, int n, int(*compare)(int x, int y)) {
	void swap(int*, int*);
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if ((*compare)(a[j - 1], a[j])) {
				swap(&a[j], &a[j - 1]);
			}
		}
	}
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int greater(int a, int b) {
	return a > b;
}

int smaller(int a, int b) {
	return a < b;
}