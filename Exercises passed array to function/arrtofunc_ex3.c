﻿// Cho mảng nguyên gồm n phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào n phần tử của mảng
// hiển thị mảng ra màn hình
// tìm giá trị lớn thứ hai trong mảng
// tìm giá trị nhỏ thứ hai trong mảng

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập vào mảng
void getElements(int a[], int n);
// hàm hiển thị mảng ra màn hình
void showElements(int a[], int n);
// hàm tìm giá trị lớn nhất
int findMax(int a[], int n);
// hàm tìm giá trị nhỏ nhất
int findMin(int a[], int n);
// hàm tìm giá trị lớn thứ hai
int findMax2(int a[], int n);
// hàm tìm giá trị nhỏ thứ hai
int findMin2(int a[], int n);

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
		int max2 = findMax2(arr, n);
		int min2 = findMin2(arr, n);
		printf("Min2 = %d\nMax2 = %d\n", min2, max2);
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

int findMax(int a[], int n) {
	int max = a[0];
	int i;
	for (i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

int findMin(int a[], int n) {
	int min = a[0];
	int i;
	for (i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

int findMax2(int a[], int n) {
	int max = findMax(a, n);
	int max2 = findMin(a, n);
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] > max2 && a[i] != max) {
			max2 = a[i];
		}
	}
	return max2;
}

int findMin2(int a[], int n) {
	int min2 = findMax(a, n);
	int min = findMin(a, n);
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] < min2 && a[i] != min) {
			min2 = a[i];
		}
	}
	return min2;
}