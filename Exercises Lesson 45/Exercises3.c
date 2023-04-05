// Bài tập đọc ghi file text số 3
#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm đọc file
void readFile(FILE* fin, int a[][50], int* m, int* n);
// hàm ghi file
void writeFile(int a[][50], int m, int n);
// hàm tính tích ma trận
void mul(int a[][50], int b[][50], int c[][50], int m, int n, int k);

int main() {
	FILE* fin = fopen("INPUT3.INP", "r"); // mo file de doc
	if (fin) {
		int m, n, k;
		int a[50][50]; // ma tran goc
		int b[50][50]; // ma tran chuyen vi
		int c[50][50] = {0}; // ma tran tich, nho khoi tao cac phan tu = 0

		// goi ham doc ma tran A
		readFile(fin, a, &m, &n);
		// goi ham doc ma tran B
		readFile(fin, b, &n, &k);
		// goi ham chuyen vi 
		mul(a, b, c, m, n, k);
		fclose(fin);
		// ghi file ket qua ma tran tich
		writeFile(c, m, k);		
	}
	else {
		puts("Khong the mo file. Vui long kiem tra lai.");
	}

	return 0;
}

void readFile(FILE* fin, int a[][50], int* m, int* n) {
	fscanf(fin, "%d%d", m, n); // doc so phan tu mang
	int i, j; // doc tung phan tu mang
	for (i = 0; i < *m; i++) {
		for (j = 0; j < *n; j++) {
			fscanf(fin, "%d", &a[i][j]);
		}
	}
}

void writeFile(int a[][50], int m, int n) {
	FILE* fout = fopen("OUTPUT3.OUT", "w"); // mo file de ghi
	if (fout) {
		fprintf(fout, "%d %d\n", m, n); // ghi so phan tu mang
		int i, j; // ghi tung phan tu mang
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fprintf(fout, "%d ", a[i][j]);
			}
			fprintf(fout, "\n"); // in xuong dong
		}
		fclose(fout);
	}
	else {
		puts("Khong the tao file. Vui long kiem tra lai.");
	}
}

void mul(int a[][50], int b[][50], int c[][50], int m, int n, int k) {
	int i, j, l;
	for (i = 0; i < m; i++) {
		for (j = 0; j < k; j++) {
			for (l = 0; l < n; l++) {
				c[i][j] += a[i][l] * b[l][j];
			}
		}
	}
}