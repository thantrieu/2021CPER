// Cho mảng nguyên gồm n phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào số n và n phần tử của mảng
// sắp xếp các phần tử của mảng theo thứ tự giảm dần
// hiển thị mảng đã sắp xếp ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập mảng và n 
void fillArr(int a[], int* n);

// hàm sắp xếp mảng
void sortDESC(int a[], int n);

// hàm hiển thị mảng
void showArrElements(int a[], int n);

// hàm main
int main() {
	// khai báo biến
	int n;
	int a[100];
	// nhập mảng
	fillArr(a, &n);
	if (n > 0) {
		// hiển thị kết quả nhập
		puts("Truoc khi sap xep: ");
		showArrElements(a, n);
		// sắp xếp mảng
		sortDESC(a, n);
		puts("\nSau khi sap xep: ");
		showArrElements(a, n);
	}
	else {
		puts("Nhap n > 0");
	}

	return 0;
}

void fillArr(int a[], int* n) {
	puts("Nhap n: ");
	scanf("%d", n);
	int i;
	for (i = 0; i < *n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void sortDESC(int a[], int n) {
	void swap(int*, int*); // hàm nguyên mẫu
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j] > a[j - 1]) { // phần tử trước nhỏ hơn phần tử sau
				swap(&a[j], &a[j - 1]); // đổi chỗ
			}
		}
	}
}

void showArrElements(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}