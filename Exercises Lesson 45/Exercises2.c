// Bài tập đọc ghi file text số 2
#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm đọc file
void readFile(int a[][50], int* m, int* n);
// hàm ghi file
void writeFile(int a[][50], int m, int n);
// hàm chuyển vị ma trận
void tranMatrix(int a[][50], int b[][50], int m, int n);

int main() {
	int n, m;
	int a[50][50]; // ma tran goc
	int b[50][50]; // ma tran chuyen vi
	// goi ham doc file
	readFile(a, &m, &n);
	// goi ham chuyen vi 
	tranMatrix(a, b, m, n);
	// ghi file
	writeFile(b, n, m);

	return 0;
}

void readFile(int a[][50], int* m, int* n) {
	FILE* fin = fopen("INPUT2.INP", "r"); // mo file de doc

	if (fin) {
		fscanf(fin, "%d%d", m, n); // doc so phan tu mang
		int i, j; // doc tung phan tu mang
		for (i = 0; i < *m; i++) {
			for (j = 0; j < *n; j++) {
				fscanf(fin, "%d", &a[i][j]);
			}
		}
		fclose(fin);
	}
	else {
		puts("Khong the mo file. Vui long kiem tra lai.");
	}
}

void writeFile(int a[][50], int m, int n) {
	FILE* fout = fopen("OUTPUT2.OUT", "w"); // mo file de ghi

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

void tranMatrix(int a[][50], int b[][50], int m, int n) {
	int i, j; // ghi tung phan tu mang
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			b[i][j] = a[j][i];
		}
	}
}