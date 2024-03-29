﻿// Giải biện luận phương trình bậc hai ax^2 + bx + c = 0
#include <stdio.h>
#include <math.h>
/*
 * @author Branium Academy
*/
int main() {
	double a, b, c; // hệ số a, b, c
	puts("Nhap he so a, b, c: ");
	scanf("%lf%lf%lf", &a, &b, &c);

	// nếu a = 0, giải phương trình bậc 1
	if (a == 0) {
		// TH1: nếu b = 0, c # 0 thì phương trình không có nghiệm
		if (b == 0 && c != 0) {
			puts("NO SOLUTION");
		}
		// TH2: nếu b = 0, c = 0 thì phương trình vô số nghiệm
		else if (b == 0 && c == 0) {
			puts("COUNTERLESS SOLUTION");
		}
		// TH3: phương trình có 1 nghiệm x = -b / a
		else {
			double x = -c / b; // nghiệm phương trình
			printf("%lf\n", x);
		}
	}
	else { // ngược lại, giải phương trình bậc 2
		double delta = b * b - 4 * a * c; // tính delta
		// TH1: delta < 0
		if (delta < 0) { // phương trình vô nghiệm
			puts("NO SOLUTION");
		}
		// TH2: delta = 0
		else if (delta == 0) { // phương trình có nghiệm kép
			double x = -b / (2 * a);
			printf("%lf\n", x);
		}
		// TH3: delta > 0
		else {
			double x1, x2; // nghiệm phương trình
			x1 = (-b - sqrt(delta)) / (2 * a);
			x2 = (-b + sqrt(delta)) / (2 * a);
			// kết luận
			printf("%lf, %lf\n", x1, x2);
		}
	}
}