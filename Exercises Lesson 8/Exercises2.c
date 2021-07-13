// Nhập vào một số nguyên n và kiểm tra n âm, dương hay bằng 0
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen n: ");
	scanf("%d", &n);
	// kiểm tra:
	if (n < 0) {
		printf("%d la so am.\n", n);
	}
	else if (n == 0) {
		printf("%d la so khong am khong duong.\n", n);
	}
	else {
		printf("%d la so duong.\n", n);
	}
}