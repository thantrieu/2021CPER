// Nhập vào số nguyên dương n và tạo ngẫu nhiên mảng gồm n số nguyên.
// Mảng được tạo sao cho các phần tử mảng không trùng nhau từng đôi

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * @author Branium Academy
*/

// hàm nhập mảng
void fillArray(int arr[], int n);
// hàm hiển thị mảng
void showArray(int a[], int n);
// hàm đếm số lần xuất hiện của x

int main() {
	int n;
	int arr[100]; // khai báo mảng tối đa 100 p.tử
	// nhập vào số phần tử mảng:
	puts("Nhap so phan tu mang 0 < n <= 1000: ");
	scanf("%d", &n);

	if (n > 0 && n <= 1000) {
		// tạo các phần tử ngẫu nhiên cho mảng
		fillArray(arr, n);

		// hiển thị các phần tử mảng
		showArray(arr, n);
	}
	else {
		puts("Nhap 0 < n <= 1000");
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

// hàm ktra xem x đã tồn tại trong mảng chưa
int isExisted(int arr[], int n, int x) {
	int i;
	for (i = 0; i < n; i++) {
		if (arr[i] == x) {
			return 1; // x đã xuất hiện
		}
	}
	// mặc định x chưa xuất hiện
	return 0;
}

void fillArray(int arr[], int n) {
	srand(time(NULL));
	int i = 0;
	int value;
	while (i < n) {
		value = rand() % 1000 + 1;
		// nếu x chưa tồn tại trong mảng
		if (!isExisted(arr, i, value)) {
			arr[i] = value;
			i++;
		}
	}
}