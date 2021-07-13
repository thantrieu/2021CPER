// Nhập vào số nguyên dương n và mảng gồm n số nguyên.
// Nhập thêm giá trị a < b, tính tổng các phần tử mảng trong đoạn [a, b]

#include <stdio.h>

/*
 * @author Branium Academy
*/

// hàm nhập mảng
void fillArray(int arr[], int n, int *a, int *b);
// hàm hiển thị mảng
void showArray(int a[], int n);
// hàm tính tổng
int sumOfElements(int arr[], int n, int a, int b);

int main() {
	int n, a, b;
	int arr[100]; // khai báo mảng tối đa 100 p.tử
	// nhập mảng
	// nhập vào số phần tử mảng:
	puts("Nhap so phan tu mang > 0");
	scanf("%d", &n);
	if (n > 0) {
		fillArray(arr, n, &a, &b);
		// tính tổng
		int sum = sumOfElements(arr, n, a, b);
		// hiển thị mảng
		showArray(arr, n);
		// hiển thị kết quả
		printf("\nTong cac phan tu nam trong doan [%d, %d] = %d\n", a, b, sum);
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

int sumOfElements(int arr[], int n, int a, int b) {
	// tìm số lần xuất hiện của x trong mảng:
	int i;
	int sum = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] >= a && arr[i] <= b) {
			sum += arr[i]; // cộng thêm vào kết quả
		}
	}
	
	return sum; // trả về kết quả tổng
}

void fillArray(int arr[], int n, int *a, int *b) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Phan tu thu %d = ", i);
		scanf("%d", &arr[i]);
	}
	puts("Nhap a < b: ");
	scanf("%d%d", a, b);
}