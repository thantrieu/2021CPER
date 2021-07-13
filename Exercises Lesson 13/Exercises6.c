// Nhập vào hai số nguyên dương m, n sau đó vẽ hình chữ nhật rỗng 
// m hàng n cột bằng các dấu *

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
				// chỉ in ra * ở hàng đầu, hàng cuối, cột đầu, cột cuối
				if (i == 1 || i == m || j == 1 || j == n) {
					printf(" * "); // in ra các dấu *
				}
				else { // những vị trí còn lại in dấu cách
					printf("   "); // in ra ba dấu cách
				}
				// dành bao nhiêu kí tự in dấu * thì dành bấy nhiêu kí tự in dấu cách
			}
			printf("\n"); // in xuống dòng
		}
	}
	else {
		puts("Nhap hai so nguyen duong m, n");
	}
}