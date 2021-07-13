// Viết chương trình thực hiện các chức năng sau:
// nhập số nguyên dương n và n phần tử của mảng, dùng con trỏ, không dùng chỉ số mảng
// hiển thị các phần tử của mảng ra màn hình không dùng chỉ số mảng
// sắp xếp mảng tăng dần, dùng con trỏ và phép so sánh con trỏ
// hiển thị kết quả sau khi sắp xếp mảng

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập n và các phần tử mảng
void fillElements(int* a, int* n);
// hàm hiển thị mảng
void showArray(int* a, int n);
// hàm sắp xếp mảng
void sortASC(int* a, int n);

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
	}
	else {
		printf("Nhap n > 0");
	}
	return 0;
}

void fillElements(int* a, int* n) {
	puts("Nhap n > 0");
	scanf("%d", n); // nhập dữ liệu thẳng vào địa chỉ n đang trỏ đến
	int i = 0;
	for (i = 0; i < *n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", a + i); // &a[i] == a + i
	}
}

void showArray(int* a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
}

void sortASC(int* a, int n) {
	void swap(int*, int*); // ham nguyen mau
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

// hàm đổi chỗ hai phần tử
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}