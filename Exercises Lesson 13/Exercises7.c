// Nhập vào số nguyên dương h sau đó vẽ tam giác 
// vuông góc trái dưới chiều cao h bằng các dấu *

#include <stdio.h>

/*
* @author Branium Academy
*/

int main() {
	int h;
	puts("Nhap so nguyen duong h:");
	scanf("%d", &h);

	if (h > 0) {
		int i, j;
		// xét từng hàng
		for (i = 1; i <= h; i++) {
			for (j = 1; j <= i; j++) {
				printf(" * "); // in ra các dấu *
			}
			// in xong i dấu * trên hàng thứ i thì xuống dòng
			printf("\n"); // in xuống dòng
		}
	}
	else {
		puts("Nhap so nguyen duong h");
	}
}