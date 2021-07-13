// Viết hàm thực hiện các chức năng sau:
// nhập vào một ma trận các số nguyên cấp m x n
// hiển thị ma trận ra màn hình
// tính giá trị lớn nhất trên từng hàng của ma trận này
// tìm giá trị lẻ nhỏ nhất trong ma trận

#include <stdio.h>

/*
 * @author Branium Academy
 */

// hàm nhập ma trận
void fillMatrix(int matrix[][50], int m, int n);

// hàm hiển thị ma trận
void showMatrix(int matrix[][50], int m, int n);

// tìm giá trị lớn nhất trên từng hàng của ma trận
void maxValueInRow(int matrix[][50], int m, int n);

// tìm giá trị lẻ nhỏ nhất trong ma trận
int minOddValue(int matrix[][50], int m, int n);

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
		// hiển thị danh sách phần tử lớn nhất trên từng hàng
		maxValueInRow(matrix, m, n);
		// tìm giá trị lẻ nhỏ nhất trong ma trận
		int minOdd = minOddValue(matrix, m, n);
		printf("Gia tri le nho nhat trong ma tran: %d", minOdd);
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

void maxValueInRow(int matrix[][50], int m, int n) {
	int i, j;
	int max;
	for (i = 0; i < m; i++) {
		max = matrix[i][0];
		for (j = 0; j < n; j++) {
			if (matrix[i][j] > max) {
				max = matrix[i][j];
			}
		}
		printf("Gia tri max hang %d = %d\n", i, max);
	}
}

int minOddValue(int matrix[][50], int m, int n) {
	int i, j;
	int min = matrix[0][0];
	// duyệt từng phần tử xem phần tử nào nhỏ nhất
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			// nếu phần tử tại vị trí i, j nhỏ nhất
			if (matrix[i][j] % 2 != 0 && matrix[i][j] < min) {
				min = matrix[i][j]; // cập nhật vào min
			}
		}
	}
	return min; // trả về kết quả
}