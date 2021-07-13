// Nhập vào số nguyên dương n và mảng gồm n số thực.
// Tính trung bình cộng các phần tử ở vị trí chẵn trong mảng
#include <stdio.h>
/*
 * @author Branium Academy
*/

// hàm nhập mảng
void fillArray(float arr[], int n);
// hàm hiển thị mảng
void showArray(float a[], int n);
// hàm tính tổng các phần tử ở vị trí chẵn
float sumOfEvenIndexElements(float arr[], int n, int* count);

int main() {
	int n;
	float arr[100]; // khai báo mảng tối đa 100 p.tử
	// nhập vào số phần tử mảng:
	puts("Nhap so phan tu mang > 0");
	scanf("%d", &n);

	if (n > 0) {
		// nhập các phần tử cho mảng
		fillArray(arr, n);
		float sum = 0;
		int count = 0; // biến lưu số phần tử được cộng dồn
		// tính tổng các phần tử ở vị trí chẵn trong mảng
		sum = sumOfEvenIndexElements(arr, n, &count);

		// hiển thị các phần tử trong mảng
		showArray(arr, n);

		printf("\nTBC = %f\n", sum / count);
	}
	else {
		puts("Nhap n > 0");
	}
}

void showArray(float arr[], int n) {
	int i;
	printf("Cac phan tu trong mang: ");
	for (i = 0; i < n; i++) {
		printf("%f ", arr[i]);
	}
}

void fillArray(float arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Phan tu thu %d = ", i);
		scanf("%f", &arr[i]); // đọc từng phần tử vào
	}
}

float sumOfEvenIndexElements(float arr[], int n, int *count) {
	int i;
	float sum = 0;
	// tính tổng các phần tử trong mảng
	for (i = 0; i < n; i += 2) {
		sum += arr[i]; // cộng dồn vào tổng
		(*count)++; // tăng biến đếm lên
	}
	return sum; // trả về kết quả tổng
}