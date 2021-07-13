// Cho mảng nguyên gồm n phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào n phần tử của mảng
// nhập giá trị x
// xóa tất cả các phần tử trong mảng có giá trị bằng x
// hiển thị kết quả trước và sau xóa ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập mảng và n 
void fillArr(int a[], int n);

// hàm xóa các phần tử có giá trị bằng x:
int removeXElements(int a[], int* n, int x);

// hàm hiển thị mảng
void showArrElements(int a[], int n);

// hàm main
int main() {
	// khai báo biến
	int n;
	int a[100];
	// nhập n
	puts("Nhap n: ");
	scanf("%d", &n);

	if (n > 0) {
		// nhập mảng
		fillArr(a, n);
		puts("Mang goc: ");
		showArrElements(a, n);
		// nhập vào giá trị x cần xóa
		int x;
		puts("\nNhap gia tri can xoa khoi mang: ");
		scanf("%d", &x);
		// xóa các phần tử bằng x khỏi mảng
		int result = removeXElements(a, &n, x);
		// hiện kết quả
		if (result) {
			printf("\nMang sau khi xoa x = %d: ", x);
			showArrElements(a, n);
		}
		else {
			printf("Khong ton tai x = %d trong mang.\n", x);
			puts("Cac phan tu mang khong thay doi.");
		}
		puts("");
	}
	else {
		puts("Nhap n > 0");
	}

	return 0;
}

void fillArr(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void showArrElements(int a[], int n) {
	int i;
	// hiển thị các phần tử làm tròn 2 chữ số đằng sau dấu phẩy
	for (i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
}

int removeXElements(int a[], int* n, int x) {
	// lưu lại giá trị gốc của số phần tử mảng
	int element = *n;
	// duyệt mảng, tìm thấy phần tử bằng x thì dồn tất cả các phần tử
	// phía bên phải x sang trái, giảm số phần tử mảng đi 1
	int k = 0;
	while (k < *n) {
		if (a[k] == x) {
			int i;
			// bắt đầu từ vị trí k
			for (i = k; i < *n - 1; i++) {
				a[i] = a[i + 1]; // dồn sang trái
			}
			*n -= 1; // giảm số phần tử đi
		}
		else { // nếu không thì tăng k lên
			k++;
		}
	}
	return element != *n; // xóa thành công nếu số lượng phần tử mảng thay đổi
}
