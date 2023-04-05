// Nhập vào số nguyên dương n và mảng gồm n số nguyên.
// Tìm giá trị lớn nhất và nhỏ nhất trong mảng

#include <stdio.h>
/*
 * @author Branium Academy
*/

// hàm nhập mảng
void fillArray(int arr[], int n);
// hàm hiển thị mảng
void showArray(int a[], int n);
// hàm tìm min
int findMinValue(int a[], int n);
// hàm tìm max
int findMaxValue(int a[], int n);

int main() {
	int n;
	int arr[100]; // khai báo mảng tối đa 100 p.tử
	// nhập vào số phần tử mảng:
	puts("Nhap so phan tu mang > 0");
	scanf("%d", &n);

	if (n > 0) {
		// nhập các phần tử mảng
		fillArray(arr, n);

		// tìm giá trị lớn nhất và nhỏ nhất
		int min = findMinValue(arr, n);
		int max = findMaxValue(arr, n);

		// hiển thị các phần tử mảng
		showArray(arr, n);

		printf("\nGia tri max = %d\nGia tri min = %d\n", max, min);
	}
	else {
		puts("Nhap n > 0");
	}
}

int findMinValue(int arr[], int n) {
	int min = arr[0]; // giả sử min là phần tử đầu
	int i; // biến chạy
	for (i = 1; i < n; i++) { // xét từ phần tử kế tiếp
		if (arr[i] < min) { // nếu phần tử thứ i < min
			min = arr[i];  // gán min là phần tử thứ i
		}
	}
	return min;
}

int findMaxValue(int arr[], int n) {
	int max = arr[0]; // giả sử max là phần tử đầu
	int i; // biến chạy
	for (i = 1; i < n; i++) { // xét từ phần tử kế tiếp
		if (arr[i] > max) { // nếu phần tử thứ i > max
			max = arr[i]; // gán max là phần tử thứ i
		}
	}
	return max;
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