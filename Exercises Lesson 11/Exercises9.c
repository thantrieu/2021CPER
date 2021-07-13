// Nhập số nguyên dương n sau đó kiểm tra xem
// n có phải số thuận nghịch hay không
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen n > 0: ");
	scanf("%d", &n);

	if (n < 0) {
		puts("Vui long nhap so nguyen n > 0");
	}
	else {
		// khai báo biến lưu giá trị đảo của n
		int revert = 0;
		int m = n; // lưu lại giá trị gốc của n để lấy số đảo
		// thực hiện đảo giá trị của n
		while (m > 0) {
			// tách lấy phần đơn vị của m và gộp vào số đảo
			revert = revert * 10 + m % 10;
			m /= 10; // giảm m đi 10 lần
		}
		// bây giờ ta có giá trị đảo của n, 
		if (revert == n) {
			printf("%d la so thuan nghich\n", n);
		}
		else {
			printf("%d khong phai so thuan nghich\n", n);
		}
	}
}