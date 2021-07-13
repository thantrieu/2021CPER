// Nhập số nguyên dương n, 0 < k < n sau đó tìm tất cả
// các số tự nhiên không lớn hơn n chia hết cho k
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n, k;
	puts("Nhap so nguyen n > 0: ");
	scanf("%d", &n);
	puts("Nhap so nguyen 0 < k < n: ");
	scanf("%d", &k);

	if (n > 0) { // nếu n duong thì mới thực hiện
		if (k > 0) {
			int i;
			// các số chia hết cho k bắt đầu từ 0 
			// cách nhau k đơn vị => i += k
			for (i = 0; i <= n; i += k) {
				printf("%d ", i); // in ra kết quả
			}
		}
		else {
			puts("Nhap k sao cho 0 < k < n");
		}
	}
	else {
		puts("Vui long nhap so tu nhien n > 0");
	}
}