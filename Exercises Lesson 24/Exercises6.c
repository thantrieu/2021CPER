// Cho số nguyên dương n và đa thức P(x) bậc n. Viết chương trình:
// nhập vào các hệ số của đa thức P
// hiển thị đa thức ra màn hình
// nhập thêm giá trị cho x và tính P(x)
// tìm đạo hàm bậc nhất của P(x)
// tính P'(x) với x nhập từ câu trước

#include <stdio.h>
#include <math.h>

/*
* @author Branium Academy
*/

// hàm nhập vào hệ số của đa thức
void getFactors(int p[], int n);
// hàm hiển thị đa thức ra màn hình
void showPolynomia(int p[], int n);
// hàm tính P(x)
float valueOfPx(int p[], int n, float x);
// hàm tìm đạo hàm P'(x)
void findDerivative(int p[], int* n, int q[]);

int main() {
	int n;
	int arr[100];
	puts("Nhap so nguyen duong n: ");
	scanf("%d", &n);
	if (n > 0) {
		puts("Nhap vao cac he so cua da thuc: ");
		getFactors(arr, n);
		puts("Da thuc P(x): ");
		showPolynomia(arr, n);
		float x;
		puts("Nhap x: ");
		scanf("%f", &x);
		float px = valueOfPx(arr, n, x);
		// làm tròn đến 2 chữ số phần thập phân
		printf("Gia tri cua da thuc P(%0.2f) = %0.2f\n", x, px);

		int m = n; // bậc đa thức P'(x)
		int q[100];

		findDerivative(arr, &m, q);
		puts("Da thuc P'(x): ");
		showPolynomia(q, m);
		printf("Gia tri cua da thuc P'(%0.2f) = %0.2f\n", x, valueOfPx(q, m, x));
	}
	else {
		puts("Vui long nhap vao so nguyen duong n");
	}
	return 0;
}

void getFactors(int a[], int n) {
	int i;
	for (i = n; i >= 0; i--) {
		// coi chỉ số là số mũ luôn
		printf("He so x^%d = ", i);
		scanf("%d", &a[i]);
	}
}

void showPolynomia(int a[], int n) {
	int i;
	for (i = n; i >= 0; i--) {
		if (a[i] != 0) {
			printf("%dx^%d", a[i], i);
			if (i > 0 && a[i - 1] > 0) {
				printf(" + ");
			}
		}
	}
	printf("\n");
}

float valueOfPx(int p[], int n, float x) {
	float result = 0;
	int i;
	for (i = 0; i <= n; i++) {
		result += p[i] * (float)pow(x, i); // tính từng phần tử
	}
	return result; // trả về kết quả
}

void findDerivative(int p[], int *n, int q[]) {
	int i;
	for (i = 0; i < *n; i++) {
		// cập nhật hệ số của x^i sau đạo hàm
		q[i] = p[i + 1] * (i + 1);
	}
	*n -= 1; // giảm bậc của n
}
