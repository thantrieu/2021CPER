// Viết hàm nguyên mẫu và định nghĩa hàm cho các chức năng sau:
// tính tổng hai số nguyên, trả về số nguyên
// tính hiệu a - b trả về số nguyên
// tính tích hai số nguyên trả về số nguyên
// tính a / b trả về giá trị float
// tính phần dư a % b trả về int

#include <stdio.h>

/*
 * @author Branium Academy
*/

// các hàm nguyên mẫu: thường để trong file .h
// hàm cộng hai số
int add(int a, int b);
// hàm trừ a cho b
int sub(int a, int b);
// hàm nhân a với b
int mul(int a, int b);
// hàm chia a cho b
float div(int a, int b);
// hàm lấy dư khi chia a cho b:
int mod(int a, int b);

// hàm main thường để trong file main.c
int main() {
	int a, b;
	puts("Nhap vao hai so nguyen a, b: ");
	scanf("%d%d", &a, &b);

	printf("%d + %d = %d\n", a, b, add(a, b));
	printf("%d - %d = %d\n", a, b, sub(a, b));
	printf("%d * %d = %d\n", a, b, mul(a, b));
	printf("%d / %d = %f\n", a, b, div(a, b));
	printf("%d %% %d = %d\n", a, b, mod(a, b));

	return 0;
}

// dưới đây là phần định nghĩa hàm: thường để trong file .c
int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int mod(int a, int b) {
	return a % b;
}

float div(int a, int b) {
	return (float)a / b;
}