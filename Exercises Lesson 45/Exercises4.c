// Bài tập đọc ghi file text số 4
#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm đọc file
void readFile(int* a, int* n, int* x, int* k, const char* fileName);
// hàm ghi file
void writeFile(int* a, int n, const char* fileName);
// hàm chèn x vào vị trí k của mảng
void insertX(int* a, int* n, int k, int x);

int main() {
	int n, k, x;
	int a[100];
	char outputFile[30];
	char inputFile[30];

	puts("Nhap ten file chua du lieu can doc: ");
	scanf("%29s", inputFile);

	// goi ham doc file
	readFile(a, &n, &x, &k, inputFile);
	if (n > 0) {
		// goi ham sap xep
		insertX(a, &n, k, x);
		puts("Nhap ten file chua du lieu can ghi: ");
		scanf("%s", outputFile);
		// ghi file
		writeFile(a, n, outputFile);
	}

	return 0;
}

void readFile(int* a, int* n, int* x, int* k, const char* fileName) {
	FILE* fin = fopen(fileName, "r"); // mo file de doc
	if (fin) {
		fscanf(fin, "%d%d%d", n, x, k); // doc so phan tu mang
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

void writeFile(int* a, int n, const char* fileName) {
	FILE* fout = fopen(fileName, "w"); // mo file de ghi
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

void insertX(int* a, int* n, int k, int x) {
	int i;
	for (i = *n; i > k; i--)
	{
		// dịch phải các phần tử từ vị trí k sang phải
		a[i] = a[i - 1]; // 1 đơn vị
	}
	a[k] = x; // gán x vào phần tử thứ k
	(*n)++; // tang so phan tu cua mang len 1
}
