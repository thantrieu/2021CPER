// Cho ba số thực a, b, c. Kiểm tra xem chúng có
// tạo thành ba cạnh tam giác hay không
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	double a, b, c; // ba cạnh a, b, c
	puts("Nhap he so a, b, c: ");
	scanf("%lf%lf%lf", &a, &b, &c);

	// điều kiện tạo thành tam giác là tổng hai cạnh bất kì
	// luôn lớn hơn cạnh còn lại
	if ((a + b > c) && (b + c > a) && (a + c > b)) {
		puts("Lap thanh ba canh tam giac.");
	}
	else {
		puts("Khong lap thanh ba canh tam giac.");
	}
}