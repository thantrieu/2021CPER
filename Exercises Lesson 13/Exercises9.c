// Nhập vào số nguyên dương h sau đó vẽ tam giác 
// cân chiều cao h bằng các dấu *

#include <stdio.h>
#include <math.h>

/*
* @author Branium Academy
*/

int main() {
	int h;
	puts("Nhap so nguyen duong h:");
	scanf("%d", &h);
	/* tam giác cân đối xứng qua cột thứ h và có chiều rộng 2h - 1
	   trên hàng thứ i ta in ra số tại các vị trí |h-j| <= i-1
	   các số này được in ra chênh một lượng i-|h-j| so với giá trị i
	   ở những vị trí còn lại in ra dấu cách
	*/
	if (h > 0) {
		int i, j;
		// xét từng hàng
		for (i = 1; i <= h; i++) {
			// trên hàng thứ i in ra i chữ số
			for (j = 1; j < 2 * h; j++) {
				if (abs(h - j) <= i - 1) {
					printf(" %d ", i - abs(h - j)); // in ra giá trị đối xứng
				}
				else {
					printf("   "); // in ra 3 dấu cách
				}
			}
			// in xong i dấu * trên hàng thứ i thì xuống dòng
			printf("\n"); // in xuống dòng
		}
	}
	else {
		puts("Nhap so nguyen duong h");
	}
}
