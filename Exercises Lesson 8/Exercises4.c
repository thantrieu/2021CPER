// Nhập vào ba số a, b, c tìm giá trị lớn nhất trong ba số
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int a, b, c;
	int max; // biến lưu giá trị lớn nhất
	puts("Nhap ba so nguyen a, b, c: ");
	scanf("%d%d%d", &a, &b, &c);
	// giả sử a là max
	max = a;
	// kiểm tra các giá trị còn lại
	if (b > max) { // nếu b lớn hơn max
		max = b;   // gán max là b
	}
	if (c > max) { // nếu c lớn hơn max
		max = c;   // gán max là c
	}
	// kết luận
	// nếu ba số bằng nhau, không có giá trị max
	if (a == b && b == c) {
		puts("NO RESULT\n");
	}
	else {
		printf("%d\n", max);
	}
}