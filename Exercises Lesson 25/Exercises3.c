// Cho mảng nguyên gồm n + 1 phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào số n và n phần tử của mảng
// sắp xếp các phần tử của mảng theo thứ tự giảm dần
// nhập x và chèn x vào mảng sao cho vẫn giữ nguyên tính chất sắp xếp
// hiển thị mảng trước và sau chèn x ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập mảng và n 
void fillArr(int a[], int* n);
// hàm sắp xếp mảng
void sortDESC(int a[], int n);
// hàm chèn x:
void insertX(int a[], int* n, int x);
// hàm hiển thị mảng
void showArrElements(int a[], int n);

// hàm main
int main() {
	// khai báo biến
	int n;
	int a[300]; // tối đa 300 phần tử
	// nhập mảng
	fillArr(a, &n);
	if (n > 0) {
		puts("Mang goc: ");
		// sắp xếp mảng
		sortDESC(a, n);
		// hiển thị mảng gồm n phần tử
		showArrElements(a, n);

		int x;
		puts("\nNhap x: ");
		scanf("%d", &x);
		insertX(a, &n, x);
		puts("\nMang sau khi chen x: ");
		showArrElements(a, n);
		puts("");
	}
	else {
		puts("Nhap n > 0");
	}

	return 0;
}

void fillArr(int a[], int* n) {
	puts("Nhap n: ");
	scanf("%d", n);
	int i;
	for (i = 0; i < *n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void sortDESC(int a[], int n) {
	void swap(int*, int*); // hàm nguyên mẫu
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j] > a[j - 1]) { // phần tử trước nhỏ hơn phần tử sau
				swap(&a[j], &a[j - 1]); // đổi chỗ
			}
		}
	}
}

void showArrElements(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertX(int a[], int* n, int x) {
	int indexToInsert(int a[], int n, int x);
	int index = indexToInsert(a, *n, x);
	// nếu nhỏ hơn tất cả các phần tử, chèn ở cuối mảng
	if (index == -1) {
		a[*n] = x;
	}
	// ngược lại dồn tất cả các phần tử từ vị trí index sang phải 1 đơn vị
	else {
		int i;
		for (i = *n; i > index; i--) {
			a[i] = a[i - 1];
		}
		// chèn x vào vị trí index
		a[index] = x;
	}
	(*n)++;
}

int indexToInsert(int a[], int n, int x) {
	// duyệt tìm phần tử đầu tiên nhỏ hơn x
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] < x) { // nếu tìm thấy
			return i; // trả về vị trí của phần tử đó
		}
	}
	return -1; // mặc định không tìm thấy, trả về -1
}