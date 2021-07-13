// Nhập vào hai số nguyên dương m, n sau đó vẽ hình chữ nhật m hàng
// n cột bằng các dấu *

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
				printf(" * "); // in ra các dấu *
			}
			printf("\n"); // in xuống dòng
		}
	}
	else {
		puts("Nhap hai so nguyen duong m, n");
	}
}