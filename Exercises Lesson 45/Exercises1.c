// Bài tập đọc ghi file text số 2
#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm đọc file
void readFile(int* a, int* n);
// hàm ghi file
void writeFile(int* a, int n);
// hàm sắp xếp
void sort(int* a, int n);

int main() {
	int n;
	int a[100];
	// goi ham doc file
	readFile(a, &n);
	// goi ham sap xep
	sort(a, n);
	// ghi file
	writeFile(a, n);

	return 0;
}

void readFile(int* a, int* n) {
	FILE* fin = fopen("INPUT.INP", "r"); // mo file de doc

	if (fin) {
		fscanf(fin, "%d", n); // doc so phan tu mang
		int i; // doc tung phan tu mang
		for (i = 0; i < *n; i++) {
			fscanf(fin, "%d", &a[i]);
		}
		fclose(fin);
	}
	else {
		puts("Khong the mo file. Vui long kiem tra lai.");
	}
}

void writeFile(int* a, int n) {
	FILE* fout = fopen("OUTPUT.OUT", "w"); // mo file de ghi

	if (fout) {
		fprintf(fout, "%d\n", n); // ghi so phan tu mang
		int i; // ghi tung phan tu mang
		for (i = 0; i < n; i++) {
			fprintf(fout, "%d ", a[i]);
		}
		fclose(fout);
	}
	else {
		puts("Khong the tao file. Vui long kiem tra lai.");
	}
}

void sort(int* a, int n) {
	void swap(int* a, int* b);
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
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