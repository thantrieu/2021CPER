// Viết hàm thực hiện các chức năng sau: 
// Thực hiện các phép cộng trừ nhân chia, lấy dư
// hiển thị kết quả dạng số nguyên, dạng số thực

#include <stdio.h>

/*
 * @author Branium Academy
*/

// hàm tính và trả về tổng hai số nguyên
int add(int a, int b) {
	return a + b;
}

// hàm tính và trả về hiệu a - b
int sub(int a, int b) {
	return a - b;
}

// hàm tính và trả về tích a * b
int mul(int a, int b) {
	return a * b;
}

// hàm tính và trả về thương a / b;
float div(int a, int b) {
	return (float)a / b;
}

// hàm lấy dư
int mod(int a, int b) {
	return a % b;
}

// hàm hiển thị kết quả ở dạng số nguyên
void showIntegerResult(int r) {
	printf("Ket qua = %d\n", r);
}

// hàm hiển thị kết quả ở dạng số thực 
void showRealResult(float r) {
	printf("Ket qua = %f\n", r);
}

// hàm main thực hiện chương trình
int main() {
	int a, b;
	puts("Nhap vao hai so nguyen a, b: ");
	scanf("%d%d", &a, &b);

	// gọi các hàm đã định nghĩa phía trên:
	int sum = add(a, b);
	printf("%d + %d = %d\n", a, b, sum);

	int dif = sub(a, b);
	printf("%d - %d = %d\n", a, b, dif);

	int prod = mul(a, b);
	printf("%d * %d = %d\n", a, b, prod);

	if (b == 0) {
		puts("Khong thuc hien duoc phep chia lay du");
	}
	else {
		int modul = mod(a, b);
		printf("%d %% %d = %d\n", a, b, modul);
	}

	float quot = 0;
	if (b == 0) {
		puts("Khong thuc hien duoc phep chia");
	} else {
		quot = div(a, b);
		printf("%d / %d = %f\n", a, b, quot);
	}

	puts("Goi ham hien thi so nguyen ket qua tong a + b: ");
	showIntegerResult(sum);

	puts("Goi ham hien thi so thuc ket qua phep chia: ");
	showRealResult(quot);

	return 0;
}