// Viết hàm thực hiện các chức năng sau:
// tìm max trong 4 số thực gán kết quả vào max, trả về void
// tìm giá trị lớn thứ hai trong 4 số nguyên, hàm trả về void

#include <stdio.h>

/*
 * @author Branium Academy
 */

 // hàm tìm max
void findMax(float a, float b, float c, float d, float* max) {
	*max = a;
	*max = (b > * max) ? b : *max;
	*max = (c > * max) ? c : *max;
	*max = (d > * max) ? d : *max;
}

// hàm tìm giá trị lớn thứ hai trong 4 số nguyên
void findSecondMax(int a, int b, int c, int d, int* max2) {
	int max = a; // tìm max
	max = (b > max) ? b : max;
	max = (c > max) ? c : max;
	max = (d > max) ? d : max;

	int min = a; // tìm min
	min = (b < min) ? b : min;
	min = (c < min) ? c : min;
	min = (d < min) ? d : min;

	*max2 = min; // tìm max2
	if (a > * max2 && a < max) {
		*max2 = a;
	}
	if (b > * max2 && b < max) {
		*max2 = b;
	}
	if (c > * max2 && c < max) {
		*max2 = c;
	}
	if (d > * max2 && d < max) {
		*max2 = d;
	}
}

int main() {
	// test
	int a, b, c, d;
	float x, y, z, t;
	// gọi hàm nhập ba số
	puts("Nhap vao 4 so thuc: ");
	scanf("%f%f%f%f", &x, &y, &z, &t);
	float max;
	findMax(x, y, z, t, &max);
	printf("findMax(%f, %f, %f, %f) = %f\n", x, y, z, t, max);

	puts("Nhap vao 4 so nguyen: ");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int max2;
	findSecondMax(a, b, c, d, &max2);
	printf("findSecondMax(%d, %d, %d, %d) = %d\n", a, b, c, d, max2);

	return 0;
}
