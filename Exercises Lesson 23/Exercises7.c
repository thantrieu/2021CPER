﻿// Nhập vào số nguyên dương n và mảng gồm n số nguyên.
// Nhập thêm giá trị x và tìm số lần xuất hiện của x trong mảng

#include <stdio.h>
/*
 * @author Branium Academy
*/

// hàm nhập mảng
void fillArray(int arr[], int n);
// hàm hiển thị mảng
void showArray(int a[], int n);
// hàm đếm số lần xuất hiện của x
int countX(int arr[], int n, int x);

int main() {
	int n;
	int arr[100]; // khai báo mảng tối đa 100 p.tử
	// nhập vào số phần tử mảng:
	puts("Nhap so phan tu mang > 0");
	scanf("%d", &n);

	if (n > 0) {
		int count = 0;
		// nhập các phần tử cho mảng
		fillArray(arr, n);

		int x;
		puts("Nhap x: ");
		scanf("%d", &x);
		// tìm số lần xuất hiện của x trong mảng:
		count = countX(arr, n, x);

		// hiển thị các phần tử mảng
		showArray(arr, n);

		printf("\nSo lan xuat hien cua %d: %d\n", x, count);
	}
	else {
		puts("Nhap n > 0");
	}
}

void showArray(int arr[], int n) {
	// hiển thị các phần tử mảng
	int i;
	printf("Cac phan tu trong mang: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void fillArray(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Phan tu thu %d = ", i);
		scanf("%d", &arr[i]);
	}
}

int countX(int arr[], int n, int x) {
	int i;
	int count = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] == x) { // nếu phần tử thứ i trùng x
			count++; // tăng biến đếm lên
		}
	}
	return count;
}