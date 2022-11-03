// Cho mảng nguyên gồm n phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào n phần tử của mảng
// hiển thị mảng ra màn hình
// tìm kiếm x trong mảng trên sử dụng thuật toán tìm kiếm tuyến tính
// tìm kiếm x trong mảng trên sử dụng thuật toán tìm kiếm nhị phân

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập mảng và x
void getElements(int a[], int n, int* x);
// hàm hiển thị mảng ra màn hình
void showElements(int a[], int n);
// hàm tìm kiếm x tuyến tính
int linearSearch(int a[], int n, int x);
// hàm tìm kiếm x nhị phân
int binarySearch(int a[], int x, int low, int height);
// hàm sắp xếp tăng dần
void sortASC(int a[], int n);

int main() {
	int n, x;
	int arr[100];
	puts("Nhap gia tri n: ");
	scanf("%d", &n);
	if (n > 0) {
		puts("Nhap cac phan tu cua mang: ");
		getElements(arr, n, &x);
		// tìm kiếm tuyến tính
		int index1 = linearSearch(arr, n, x);
		// hiển thị mảng
		printf("Cac phan tu trong mang: ");
		showElements(arr, n);
		printf("Ket qua tim kiem tuyen tinh:\n");
		if (index1 != -1) {
			printf("Tim thay x tai vi tri %d\n", index1);
		}
		else {
			puts("Khong tim thay x");
		}

		// tìm kiếm nhị phân:
		// b1 ta sắp xếp mảng:
		sortASC(arr, n);
		// b2: tìm kiếm
		int index2 = binarySearch(arr, x, 0, n - 1);

		printf("Cac phan tu trong mang: ");
		showElements(arr, n);
		printf("Ket qua tim kiem nhi phan:\n");
		if (index2 != -1) {
			printf("Tim thay x tai vi tri %d\n", index2);
		}
		else {
			puts("Khong tim thay x");
		}
	}
	else {
		puts("Nhap n > 0");
	}

	return 0;
}

void getElements(int a[], int n, int* x) {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("x = ");
	scanf("%d", x);
}

void showElements(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int linearSearch(int a[], int n, int x) {
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] == x) { // nếu phần tử thứ i trùng x
			return i; // trả về chỉ số i
		}
	}
	return -1; // mặc định trả về -1 nếu không tìm thấy
}

int binarySearch(int a[], int x, int l, int h) {
	while (l <= h) {
		// lấy chỉ số giữa
		int mid = (l + h) / 2;
		if (a[mid] == x) { // nếu phần tử chính giữa trùng x
			return mid; // trả về chỉ số mid
		}// nếu phần tử này nhỏ hơn x, tìm phía bên phải mid
		else if (a[mid] < x) {
			l = mid + 1; // cập nhật giới hạn dưới
		}// ngược lại ta tìm x bên trái phần tử mid
		else {
			h = mid - 1; // cập nhật giới hạn trên
		}
	}
	return -1; // mặc định trả về -1 nếu không tìm thấy
}

void sortASC(int a[], int n) {
	void swap(int*, int*);
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(&a[j], &a[j - 1]);
			}
		}
	}
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}