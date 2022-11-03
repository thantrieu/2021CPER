// Viết chương trình thực hiện các chức năng sau:
// nhập vào số nguyên dương n và n phần tử của một mảng nguyên
// viết hàm đổi chỗ hai phần tử
// sắp xếp mảng trên theo thứ tự giảm dần
// tìm giá trị dầu tiên xuất hiện nhiều nhất trong mảng
// hiển thị mảng trước và sau khi sắp xếp

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập n và n phần tử của mảng
void getElements(int* a, int* n);
// hàm đổi chỗ
void swap(int* a, int* b);
// hàm sắp xếp
void sortDESC(int* a, int n);
// hàm tìm giá trị đầu tiên xuất hiện nhiều nhất trong mảng
void findMostAppear(int* a, int n);
// hàm hiển thị mảng
void showArray(int* a, int n);

int main() {
	int n;
	int a[100];
	getElements(a, &n);
	if (n > 0) {
		puts("Cac phan tu trong mang: ");
		showArray(a, n);
		puts("\nCac phan tu sau khi sap xep: ");
		sortDESC(a, n);
		showArray(a, n);
		// tìm giá trị đầu tiên xuất hiện nhiều nhất trong mảng
		findMostAppear(a, n);
	}
	else {
		puts("Nhap n > 0");
	}

	return 0;
}

void getElements(int* a, int* n) {
	puts("Nhap so nguyen duong n: ");
	scanf("%d", n);// con trỏ không cần & trước tên biến
	int i;
	for (i = 0; i < *n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void sortDESC(int* a, int n) {
	int i, j;
	// sắp xếp theo kiểu buble sort
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

void showArray(int* a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

void findMostAppear(int* a, int n) {
	int countX(int*, int, int); // hàm nguyên mẫu
	int i;
	int max = 1;
	// tìm số lần xuất hiện nhiều nhất trong các phần tử
	for (i = 0; i < n; i++) {
		int o = countX(a, n, a[i]); // t 
		if (o > max) {
			max = o;
		}
	}
	// tìm phần tử đầu tiên thỏa mãn xuất hiện nhiều nhất:
	for (i = 0; i < n; i++) {
		if (countX(a, n, a[i]) == max) {
			printf("\nPhan tu dau tien xuat hien nhieu nhat: %d\n", a[i]);
			break; // kết thúc vòng lặp
		}
	}
}

// hàm đếm số lần xuất hiện của x
int countX(int* a, int n, int x) {
	int count = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] == x) {
			count++;
		}
	}
	return count;
}