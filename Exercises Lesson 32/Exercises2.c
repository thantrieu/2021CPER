// Viết chương trình sử dụng con trỏ hàm thực hiện các chức năng sau:
// nhập vào các phần tử mảng
// hiển thị mảng dùng toàn bộ thao tác con trỏ
// hiển thị mảng sử dụng tên mảng và chỉ số mảng bình thường

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập các phần tử mảng
void getElements(int* a, int n);
// hàm hiển thị các phần tử mảng cách thông thường
void show1(const int* a, int n);
// hàm hiển thị các phần tử mảng dùng con trỏ
void show2(const int* a, int n);

int main() {
	int a[100];
	int n;
	puts("Nhap n: ");
	scanf("%d", &n);
	if (n > 0) {
		getElements(a, n);
		// khai báo con trỏ hàm
		void (*show)(const int*, int) = NULL;
		int choice;
		printf("Chon cach hien thi mang:\n1. Thong thuong.\n2. Dung con tro.\nBan chon? ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			// hiển thị cách thông thường
			show = show1;
			break;
		case 2:
			// hiển thị cách sử dụng con trỏ
			show = show2;
			break;
		default:
			puts("Nhap dung tuy chon 1 hoac 2.");
			break;
		}
		if (show != NULL) {
			puts("Cac phan tu mang: ");
			(*show)(a, n);
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

void show1(const int* a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

void show2(const int* a, int n) {
	const int* aPtr = a;
	for (; aPtr < (a + n); aPtr++) {
		printf("%d ", *aPtr);
	}
}