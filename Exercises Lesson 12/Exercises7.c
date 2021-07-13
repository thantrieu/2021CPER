// Nhập số nguyên dương n và tính tổng S = 1 + 1/2^3 + ... + 1/n^3
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen 0 <= n <= 23: ");
	scanf("%d", &n);

	if (n <= 0) {
		puts("Vui long nhap so nguyen duong n");
	}
	else {
		float sum = 0;
		int i = 1;
		while (i <= n) { // thực hiện chừng nào i <= n
			// nhớ ép kiểu sang float
			sum += (float)1 / (i * i * i); // cộng thêm i^3
			i++;
		}
		// lúc này ta đã có kết quả:
		printf("S = %f\n", sum);
	}
}