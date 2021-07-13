// Nhập vào hai số nguyên a, b. Thực hiện các phép +-*/%
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int a, b;
	puts("Nhap vao hai so nguyen a, b: ");
	// để đọc dữ liệu vào luôn nhớ dùng & trước tên biến
	// %d%d luôn viết liền nhau
	scanf("%d%d", &a, &b); // đọc dữ liệu vào
	printf("%d + %d = %d\n", a, b, a + b); // cộng
	printf("%d - %d = %d\n", a, b, a - b); // trừ
	printf("%d * %d = %d\n", a, b, a * b); // nhân
	// ép kiểu tử số sang float để có giá trị chính xác a / b
	printf("%d / %d = %f\n", a, b, (float)a / b); // chia
	// để in ra kí hiệu % ta dùng hai dấu %%
	printf("%d %% %d = %d\n", a, b, a % b); // lấy phần dư
}
