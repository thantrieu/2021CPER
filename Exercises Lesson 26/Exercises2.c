// Cho mảng nguyên gồm n phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào n phần tử của mảng
// tìm số lần xuất hiện của từng phần tử trong mảng
// hiển thị kết quả ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập mảng và x
void getElements(int a[], int n);
// hàm đếm số lần xuất hiện của x
int countX(int a[], int n, int x);
// hàm kiểm tra xem x đã xuất hiện trong mảng chưa
int isExisted(int a[], int n, int x);
// hàm liệt kê kết quả
void showResult(int a[], int n);

int main() {
	int n;
	int arr[100];
	puts("Nhap so phan tu mang: ");
	scanf("%d", &n);
	if (n > 0) {
		puts("Nhap cac phan tu mang: ");
		getElements(arr, n);
		showResult(arr, n);
	}
	else {
		puts("Nhap n > 0");
	}
	return 0;
}

int isExisted(int a[], int n, int x) {
	int i;
	for (i = 0; i < n; i++) {
		if (x == a[i]) {
			return 1; // trả về true - x đã tồn tại
		}
	}
	return 0; // mặc định chưa tồn tại x trong mảng
}

int countX(int a[], int n, int x) {
	int i;
	int count = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == x) { // nếu phần tử thứ i trùng x
			count++; // tăng biến đếm
		}
	}
	return count; // kết quả đếm x
}

void showResult(int a[], int n) {
	int i;
	printf("Ket qua: \n");
	// duyệt từng phần tử mảng
	for (i = 0; i < n; i++) {
		// nếu đến thời điểm hiện tại(i) mà giá trị a[i] 
		if (!isExisted(a, i, a[i])) { // chưa xuất hiện
			int count = countX(a, n, a[i]); // thì đếm
			printf("%d: %d\n", a[i], count); // hiện kết quả
		}
	}
}

void getElements(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}