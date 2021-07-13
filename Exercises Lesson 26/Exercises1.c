// Cho mảng nguyên gồm n phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào n phần tử của mảng
// hiển thị mảng ra màn hình
// tìm kiếm các giá trị trong mảng gần x nhất

#include <stdio.h>
#include <math.h>

/*
* @author Branium Academy
*/

// hàm nhập mảng và x
void getElements(int a[], int n, int* x);
// hàm hiển thị mảng ra màn hình
void showElements(int a[], int n);
// hàm tìm giá trị gần x nhất
int closestX(int a[], int n, int x);
// hàm tìm kiếm giá trị gần x nhất
int listedClosestX(int a[], int n, int x);

int main() {
	int n, x;
	int arr[100];
	puts("Nhap gia tri n: ");
	scanf("%d", &n);
	if (n > 0) {
		puts("Nhap cac phan tu cua mang: ");
		getElements(arr, n, &x);
		// tìm giá trị gần x nhất
		puts("Cac gia tri gan x nhat: ");
		listedClosestX(arr, n, x);
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

int closestX(int a[], int n, int x) {
	int i;
	int min = abs(a[0] - x);
	// duyệt tìm giá trị gần x nhất
	for (i = 1; i < n; i++) {
		int v = abs(a[i] - x);
		if (v < min) {
			min = v;
		}
	}
	return min;
}

int listedClosestX(int a[], int n, int x) {
	int count = 0;
	int minValue = closestX(a, n, x);
	int i;
	for (i = 0; i < n; i++) {
		if (abs(a[i] - x) == minValue) { // tìm thấy giá trị thỏa mãn đk
			printf("%8d", a[i]); // hiển thị ra màn hình
			count++;
		}
	}
	return count;
}