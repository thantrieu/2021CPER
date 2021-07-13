// Tính tổng bình phương các chữ số của n

#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen duong n: ");
	scanf("%d", &n);
	if (n < 0) {
		puts("Vui long nhap so nguyen duong n");
	}
	else {
		int sum = 0;
		while (n > 0) {
			int digit = n % 10; // lấy chữ số phần đơn vị của n
			sum += digit * digit; // cộng bình phương chữ số vào sum
			n /= 10; // giảm n đi 10 lần để loại bỏ phần đơn vị đã lấy
		}
		// lúc này có kết quả rồi, in ra thôi
		printf("Sum = %d\n", sum);
	}
}