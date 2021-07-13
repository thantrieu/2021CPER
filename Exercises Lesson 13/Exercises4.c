// Nhập vào hai số nguyên dương m, n sau đó vẽ hình chữ nhật m hàng
// mỗi hàng liệt kê các giá trị từ 1 đến n.

#include <stdio.h>

/*
* @author Branium Academy
*/

int main() {
	int m, n;
	puts("Nhap hai so nguyen duong m, n:");
	scanf("%d%d", &m, &n);

	if (m > 0 && n > 0) {
		int i, j;
		for (i = 1; i <= m; i++) {
			for (j = 1; j <= n; j++) {
				printf("%d ", j); // in ra các phần tử trên cùng hàng
			}
			printf("\n"); // in xuống dòng
		}

	}
	else {
		puts("Nhap hai so nguyen duong m, n");
	}

}