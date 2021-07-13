// Cho ba số thực a, b, c. Kiểm tra xem chúng có
// tạo thành ba cạnh tam giác vuông hay không
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	double a, b, c; // ba cạnh a, b, c
	puts("Nhap he so a, b, c: ");
	scanf("%lf%lf%lf", &a, &b, &c);

	// điều kiện tạo thành tam giác vuông: tạo thành tam giác và
	// tổng bình phương hai cạnh kề bằng bình phương cạnh huyền
	if ((a + b > c) && (b + c > a) && (a + c > b)) {
		// điều kiện tạo tam giác vuông
		if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
			puts("Tao thanh tam giac vuong");
		}
		else { // không thỏa mãn
			puts("Khong tao tam giac vuong");
		}
	}
	else {
		puts("Khong lap thanh ba canh tam giac.");
	}
}