// Cho mảng thực gồm n phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào số n và n - 1 phần tử của mảng
// nhập x và một giá trị k sao cho 0 <= k < n
// chèn x vào vị trí k của mảng
// hiển thị mảng trước và sau chèn x ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập mảng và n 
void fillArr(float a[], int* n);
// hàm nhập x và k
void getKX(int n, float* x, int* k);
// hàm chèn x:
void insertXAtK(float a[], int n, float x, int k);
// hàm hiển thị mảng
void showArrElements(float a[], int n);

// hàm main
int main() {
	// khai báo biến
	int n;
	float a[100];
	// nhập mảng
	fillArr(a, &n);
	if (n > 0) {
		puts("Mang goc: ");
		showArrElements(a, n - 1);

		int k;
		float x;
		getKX(n, &x, &k);
		insertXAtK(a, n, x, k);
		puts("\nMang sau khi chen x: ");
		showArrElements(a, n);
		puts("");
	}
	else {
		puts("Nhap n > 0");
	}

	return 0;
}

void getKX(int n, float* x, int* k) {
	puts("\nNhap x: ");
	scanf("%f", x);
	while (1) {
		printf("Nhap 0 <= k < %d: ", n);
		scanf("%d", k);
		// nếu nhập đúng k thỏa mãn đk thì sẽ kết thúc vòng lặp
		// không thì cứ đợi đấy!
		if (*k >= 0 && *k < n) {
			break;
		}
	}
}

void fillArr(float a[], int* n) {
	puts("Nhap n: ");
	scanf("%d", n);
	int i;
	for (i = 0; i < *n - 1; i++) {
		printf("a[%d] = ", i);
		scanf("%f", &a[i]);
	}
}

void showArrElements(float a[], int n) {
	int i;
	// hiển thị các phần tử làm tròn 2 chữ số đằng sau dấu phẩy
	for (i = 0; i < n; i++) {
		printf("%8.2f", a[i]);
	}
}

void insertXAtK(float a[], int n, float x, int k) {
	// nếu k < n - 1 thì dồn các phần tử bên phải vị trí k
	// sang phải 1 vị trí
	if (k < n - 1) {
		int i;
		for (i = n - 1; i > k; i--) {
			a[i] = a[i - 1];
		}
	}
	// nếu k >= n - 1 thì bỏ qua bước trên
	// chèn x vào vị trí k
	a[k] = x; // xong
}