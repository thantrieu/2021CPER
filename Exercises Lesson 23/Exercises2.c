// Nhập vào số nguyên dương n và mảng gồm n số nguyên.
// Tính trung bình cộng các phần tử trong mảng
#include <stdio.h>
/*
 * @author Branium Academy
*/

// hàm nhập mảng
void fillArray(int arr[], int n);
// hàm hiển thị mảng
void showArray(int a[], int n);
// hàm tính tổng các phần tử
int sumOfElements(int arr[], int n);

int main() {
	int n;
	int arr[100]; // khai báo mảng tối đa 100 p.tử
	// nhập vào số phần tử mảng:
	puts("Nhap so phan tu mang > 0");
	scanf("%d", &n);
	// gọi hàm nhập các phần tử cho mảng
	fillArray(arr, n);

	if (n > 0) {
		// hiển thị các phần tử mảng
		showArray(arr, n);

		// gọi hàm tính tổng các phần tử
		int sum = sumOfElements(arr, n);

		printf("\nTBC = %f\n", (float)sum / n);
	}
	else {
		puts("Nhap n > 0");
	}
}

void showArray(int arr[], int n) {
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

int sumOfElements(int arr[], int n) {
	int i;
	int sum = 0;
	// tính tổng các phần tử trong mảng
	for (i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum; // trả về kết quả tổng
}