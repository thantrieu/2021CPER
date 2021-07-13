// Nhập số nguyên dương n sau đó tính
// tích các chữ số của n
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen n > 0: ");
	scanf("%d", &n);

	if (n < 0) {
		puts("Nhap so nguyen n > 0");
	}
	else {
		// Ý tưởng của việc tính tích các chữ số của n là
		// B1: tách từng số ở phần đơn vị ra qua n%10 và nhân vào tích
		// B2: giảm n đi 10 lần để loại bỏ giá trị phần đơn vị
		// lặp lại B1, B2 khi n > 0
		int prod = 1;
		if (n == 0) {
			prod = 0;
		}
		while (n > 0) {
			prod *= n % 10;
			n /= 10;
		}
		printf("Product = %d\n", prod);
	}
}