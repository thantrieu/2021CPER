// Viết hàm kiểm tra ba số thực cho trước có tạo thành tam giác?
// |a - b| < c < a + b

#include <stdio.h>
#include <math.h>

/*
 * @author Branium Academy
 */

 // hàm kiểm tra lập tam giác
int isTriangle(double a, double b, double c) {
	if (fabs(a - b) < c && c < (a + b)) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	// test
	double a, b, c;
	puts("Nhap ba so thuc a, b, c: ");
	scanf("%lf%lf%lf", &a, &b, &c);

	if (isTriangle(a, b, c)) {
		puts("Ba so la ba canh tam giac");
	}
	else {
		puts("Khong tao thanh tam giac");
	}

	return 0;
}
