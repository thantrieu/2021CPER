// Nhập vào số nguyên dương n và mảng gồm n số nguyên.
// Tính trung bình cộng các phần tử lẻ trong mảng

#include <stdio.h>
/*
 * @author Branium Academy
*/

// hàm nhập mảng
void fillArray(int arr[], int n);
// hàm hiển thị mảng
void showArray(int a[], int n);
// hàm tính tổng các phần tử lẻ
int sumOfOddElements(int arr[], int n, int* count);

int main() {
	int n;
	int arr[100]; // khai báo mảng tối đa 100 p.tử
	// nhập vào số phần tử mảng:
	puts("Nhap so phan tu mang > 0");
	scanf("%d", &n);

	if (n > 0) {
		int sum = 0;
		int count = 0; // biến lưu số phần tử được cộng dồn
		// nhập các phần tử cho mảng
		fillArray(arr, n);

		// tính tổng các phần tử lẻ trong mảng
		sum = sumOfOddElements(arr, n, &count);

		// hiển thị các phần tử mảng
		showArray(arr, n);

		printf("\nTBC = %f\n", (float)sum / count);
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

int sumOfOddElements(int arr[], int n, int* count) {
	int i;
	int sum = 0;
	// tính tổng các phần tử lẻ trong mảng
	for (i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) { // nếu phần tử thứ i lẻ
			sum += arr[i]; // cộng dồn vào tổng
			(*count)++; // tăng biến đếm số phần tử lên
		}
	}
	return sum; // trả về kết quả tổng
}