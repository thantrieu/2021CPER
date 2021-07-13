// Nhập số nguyên dương n sau đó tính
// tổng các chữ số của n
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
		// Ý tưởng của việc tính tổng các chữ số của n là
		// B1: tách từng số ở phần đơn vị ra qua n%10 và cộng vào tổng
		// B2: giảm n đi 10 lần để loại bỏ giá trị phần đơn vị
		// lặp lại B1, B2 khi n > 0
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		printf("Sum = %d\n", sum);
	}
}