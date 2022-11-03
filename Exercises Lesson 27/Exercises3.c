// Viết hàm thực hiện các chức năng sau:
// nhập vào một ma trận các số nguyên cấp m x n
// tìm ma trận chuyển vị của ma trận này
// hiển thị ma trận ra màn hình

#include <stdio.h>

/*
 * @author Branium Academy
 */

// hàm nhập ma trận
void fillMatrix(int matrix[][50], int m, int n);

// hàm hiển thị ma trận
void showMatrix(int matrix[][50], int m, int n);

// hàm tìm ma trận chuyển vị
void tranMatrix(int matrix[][50], int m, int n, int tMatrix[][50]);

int main() {
	int m, n;
	int matrix[50][50];
	puts("Nhap so phan tu cua ma tran: ");
	scanf("%d%d", &m, &n);

	if (m > 0 && n > 0) {
		// nhập vào ma trận
		fillMatrix(matrix, m, n);
		// hiển thị ma trận
		puts("Ma tran cua ban la:");
		showMatrix(matrix, m, n);
		// ma trận chuyển vị
		puts("Ma tran chuyen vi: ");
		int tMatrix[50][50];
		tranMatrix(matrix, m, n, tMatrix);
		showMatrix(tMatrix, n, m);
	}
	else {
		puts("Nhap m, n > 0");
	}
	return 0;
}

void tranMatrix(int matrix[][50], int m, int n, int tMatrix[][50]) {
	int i, j;
	// ma trận chuyển vị có cấp n x m
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			// b[i][j] = a[j][i]
			tMatrix[i][j] = matrix[j][i];
		}
	}
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