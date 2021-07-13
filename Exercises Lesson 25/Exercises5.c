// Cho mảng thực gồm n phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào số n và n phần tử của mảng
// nhập giá trị k sao cho 0 <= k < n
// nhập xóa phần tử tại vị trí k khỏi mảng
// hiển thị mảng trước và sau xóa ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập mảng và n 
void fillArr(float a[], int* n);

// hàm nhập x và k
void getK(int n, int* k);

// hàm xóa phần tử tại vị trí k:
void removeElementAtK(float a[], int* n, int k);

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
		showArrElements(a, n);

		int k;
		getK(n, &k);
		removeElementAtK(a, &n, k);
		puts("\nMang sau khi xoa phan tu tai vi tri k: ");
		showArrElements(a, n);
		puts("");
	}
	else {
		puts("Nhap n > 0");
	}

	return 0;
}

void getK(int n, int* k) {
	while (1) {
		printf("\nNhap 0 <= k <= %d: ", n);
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
	for (i = 0; i < *n; i++) {
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

void removeElementAtK(float a[], int* n, int k) {
	// nếu k < n - 1 thì dồn các phần tử bên phải vị trí k
	// sang trái 1 vị trí
	if (k < *n - 1) {
		int i;
		for (i = k; i < *n - 1; i++) {
			a[i] = a[i + 1]; // dồn sang trái
		}
	}
	*n -= 1; // giảm số phần tử đi
}
