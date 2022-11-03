// Viết hàm thực hiện các chức năng sau:
// nhập vào hai ma trận các số nguyên cấp m x n
// hiển thị ma trận A, B và tổng ra màn hình

#include <stdio.h>

/*
 * @author Branium Academy
 */

// hàm nhập ma trận
void fillMatrix(int matrix[][50], int m, int n);

// hàm hiển thị ma trận
void showMatrix(int matrix[][50], int m, int n);

int main() {
	int m, n;
	int a[50][50]; // ma trận A
	puts("Nhap so phan tu cua ma tran: ");
	scanf("%d%d", &m, &n);

	if (m > 0 && n > 0) {
		// nhập vào ma trận A
		puts("Nhap ma tran A: ");
		fillMatrix(a, m, n);
		// hiển thị ma trận
		puts("Ma tran A:");
		showMatrix(a, m, n);
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
			printf("%d ", matrix[i][j]);
		}
		puts("");
	}
}
