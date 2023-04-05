// Viết chương trình thực hiện các chức năng sau:
// nhập số nguyên dương n và n phần tử của mảng
// hiển thị các phần tử mảng
// tìm kiếm phần tử trong mảng
// sắp xếp các phần tử mảng
#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập n và các phần tử mảng
void fillElements(int* const a, int* n);
// hàm hiển thị mảng chỉ cho phép đọc dữ liệu và không được thay đổi
// con trỏ mảng
void showArray(const int* const a, const int n);
// hàm sắp xếp mảng cho phép thay đổi giá trị phần tử mảng
// không cho phép thay đổi con trỏ mảng
void sortASC(int* const a, const int n);
// hàm tìm kiếm chỉ đọc
int searchElement(const int* const a, const int n, const int key);

// nơi gọi hàm
int main() {
	int n;
	int a[100];
	fillElements(a, &n);
	if (n > 0) {
		puts("Danh sach phan tu mang: ");
		showArray(a, n);
		sortASC(a, n);
		puts("\nCac phan tu sau khi sap xep: ");
		showArray(a, n);
		// tìm x
		int x;
		puts("\nNhap x = ");
		scanf("%d", &x);
		// dùng toán tử ba ngôi
		(searchElement(a, n, x) != -1) ? printf("%d ton tai trong mang", x) 
			: printf("%d khong ton tai trong mang", x);
	}
	else {
		printf("Nhap n > 0");
	}
	return 0;
}

int searchElement(const int* const a, const int n, const int key) {
	int i;
	for (i = 0; i < n; i++) {
		if (*(a + i) == key) {
			return i; // trả về chỉ số phần tử
		}
	}
	return -1; // mặc định không tìm thấy
}

void fillElements(int* const a, int* n) {
	puts("Nhap n > 0");
	scanf("%d", n); // nhập dữ liệu thẳng vào địa chỉ n đang trỏ đến
	int i = 0;
	for (i = 0; i < *n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", a + i); // &a[i] == a + i
	}
}

void showArray(const int* const a, const int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
}

void sortASC(int* const a, const int n) {
	void swap(int* const, int* const); // ham nguyen mau
	int i;
	int* aPtr;
	for (i = 0; i < n - 1; i++) {
		for (aPtr = (a + n - 1); aPtr > (a + i); aPtr--) {
			if (*aPtr < *(aPtr - 1)) { // nếu phần tử sau nhỏ hơn pt trước
				swap(aPtr, aPtr - 1); // đổi chỗ chúng cho nhau
			}
		}
	}
}

// hàm đổi chỗ hai phần tử, không thay đổi con trỏ
void swap(int* const a, int* const b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}