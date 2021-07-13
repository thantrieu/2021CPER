﻿// Cho mảng nguyên gồm n phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào n phần tử của mảng
// hiển thị mảng ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập vào mảng
void getElements(int a[], int n);
// hàm hiển thị mảng ra màn hình
void showElements(int a[], int n);

int main() {
	int n;
	int arr[100];
	puts("Nhap so nguyen duong n: ");
	scanf("%d", &n);
	if (n > 0) {
		puts("Nhap vao cac phan tu mang: ");
		getElements(arr, n);
		puts("Cac phan tu trong mang la: ");
		showElements(arr, n);
	}
	else {
		puts("Vui long nhap vao so nguyen duong n");
	}
	return 0;
}


void getElements(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void showElements(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
