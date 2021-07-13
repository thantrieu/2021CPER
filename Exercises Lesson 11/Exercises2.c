// Nhập số tự nhiên n và k < n sau đó hiển thị các số lẻ
// trong đoạn [k, n]
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n, k;
	puts("Nhap so tu nhien n > 0: ");
	scanf("%d", &n);
	puts("Nhap k < n: ");
	scanf("%d", &k);

	if (n > 0) {
		printf("Cac so le trong doan [0, %d]: ", n);
		int i;
		for (i = k; i <= n; i++) {
			if (i % 2 != 0) {
				printf("%d ", i);
			}
		}
	}
	else {
		puts("Vui long nhap so tu nhien n > 0");
	}
}