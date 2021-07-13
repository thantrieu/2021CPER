// Nhập số nguyên dương a, b và kiểm tra xem chúng có phải là
// số nguyên tố cùng nhau hay không
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int a, b;
	puts("Nhap 2 so nguyen duong a, b: ");
	scanf("%d%d", &a, &b);

	if (a <= 0 || b <= 0) {
		puts("Vui long nhap hai so nguyen duong a, b");
	}
	else {
		// số nguyên tố cùng nhau là cặp số có ước chung lớn nhất
		// bằng 1
		// tìm ước chung lớn nhất của hai số a, b
		while (a != b) {
			if (a > b) {
				a -= b;
			}
			else {
				b -= a;
			}
		}
		// lúc này a = b nên ta kiểm tra a hoặc b đều ok
		
		if (a == 1) {
			puts("Hai so nguyen to cung nhau");
		}
		else {
			puts("Hai so khong nguyen to cung nhau");
		}
	}
}