// Viết hàm thực hiện các chức năng sau:
// nhập vào hai ma trận các số nguyên cấp m x n
// tính tổng hai ma trận A, B
// hiển thị ma trận A, B và tổng ra màn hình

#include <stdio.h>

/*
 * @author Branium Academy
 */

// hàm nhập ma trận
void fillMatrix(int matrix[][50], int m, int n);

// hàm hiển thị ma trận
void showMatrix(int matrix[][50], int m, int n);

// hàm tính tổng hai ma trận
void sumMatrix(int a[][50], int b[][50], int c[][50], int m, int n);

int main() {
	int m, n;
	int a[50][50]; // ma trận A
	int b[50][50]; // ma trận B
	int s[50][50]; // ma trận tổng
	puts("Nhap so phan tu cua ma tran: ");
	scanf("%d%d", &m, &n);

	if (m > 0 && n > 0) {
		// nhập vào ma trận A
		puts("Nhap ma tran A: ");
		fillMatrix(a, m, n);
		// nhập vào ma trận B
		puts("Nhap ma tran B: ");
		fillMatrix(b, m, n);
		// tính tổng
		sumMatrix(a, b, s, m, n);
		// hiển thị ma trận
		puts("\nMa tran A:");
		showMatrix(a, m, n);
		puts("\nMa tran B:");
		showMatrix(b, m, n);
		puts("\nMa tran S:");
		showMatrix(s, m, n);
	}
	else {
		puts("Nhap m, n > 0");
	}
	return 0;
}

void fillMatrix(int matrix[][50], int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}

void showMatrix(int matrix[][50], int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			// dành 5 vị trí in ra mỗi giá trị của ma trận
			printf("%5d", matrix[i][j]);
		}
		puts("");
	}
}

void sumMatrix(int a[][50], int b[][50], int s[][50], int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			// tính tổng ma trận
			s[i][j] = a[i][j] + b[i][j];
		}
	}
}