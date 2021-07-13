// Viết hàm thực hiện các chức năng sau:
// nhập vào hai số nguyên dương m, n
// vẽ ma trận trôn ốc cấp m x n xoay theo chiều tăng kim đồng hồ, bắt đầu từ 0
// hiển thị ma trận trên ra màn hình

#include <stdio.h>

/*
 * @author Branium Academy
 */

// hàm nhập hai số nguyên dương
void fillAB(int* m, int* n);

// hàm vẽ ma trận xoáy ốc
void drawSpiral(int matrix[50][50], int m, int n);

// hàm hiển thị ma trận
void showMatrix(int matrix[][50], int m, int n);

int main() {
	int m, n;
	fillAB(&m, &n);
	int matrix[50][50];
	drawSpiral(matrix, m, n);
	// hiển thị kết quả:
	showMatrix(matrix, m, n);
	return 0;
}

void fillAB(int* m, int* n) {
	puts("Nhap hai so nguyen m, n > 0");
	scanf("%d%d", m, n);
}

void increaseValue(int x1, int x2, int y1, int y2, int a[50][50], int* d) {
	void decreaseValue(int, int, int, int, int a[][50], int*);
	int i;
	for (i = x1; i <= x2; i++) {
		a[y1][i] = (*d)++;
	}

	for (i = y1 + 1; i <= y2; i++) {
		a[i][x2] = (*d)++;
	}

	if (x1 < x2 && y1 < y2) {
		y1++;
		x2--;
		decreaseValue(x1, x2, y1, y2, a, d);
	}
}

void decreaseValue(int x1, int x2, int y1, int y2, int a[50][50], int* d) {
	void increaseValue(int, int, int, int, int a[][50], int*);
	int i;
	for (i = x2; i >= x1; i--) {
		a[y2][i] = (*d)++;
	}

	for (i = y2 - 1; i >= y1; i--) {
		a[i][x1] = (*d)++;
	}

	if (x1 < x2 && y1 < y2) {
		y2--;
		x1++;
		increaseValue(x1, x2, y1, y2, a, d);
	}
}

void drawSpiral(int matrix[50][50], int m, int n) {
	void increaseValue(int, int, int, int, int a[][50], int*);
	void decreaseValue(int, int, int, int, int a[][50], int*);
	int d = 0;
	int x1 = 0, x2 = n - 1;
	int y1 = 0, y2 = m - 1;
	increaseValue(x1, x2, y1, y2, matrix, &d);
}

void showMatrix(int matrix[][50], int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			// dành 5 vị trí in ra mỗi giá trị của ma trận
			printf("%5d", matrix[i][j]);
		}
		puts("\n");
	}
}