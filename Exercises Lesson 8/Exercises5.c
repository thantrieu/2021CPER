// Nhập vào ba số a, b, c tìm giá trị nhỏ nhất trong ba số
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int a, b, c;
	int min; // biến lưu giá trị nhỏ nhất
	puts("Nhap ba so nguyen a, b, c: ");
	scanf("%d%d%d", &a, &b, &c);
	// giả sử a là min
	min = a;
	// kiểm tra các giá trị còn lại
	if (b < min) { // nếu b nhỏ hơn min
		min = b;   // gán min là b
	}
	if (c < min) { // nếu c nhỏ hơn min
		min = c;   // gán min là c
	}
	// kết luận
	// nếu ba số bằng nhau, không có giá trị min
	if (a == b && b == c) {
		puts("NO RESULT");
	}
	else {
		printf("%d\n", min);
	}
}