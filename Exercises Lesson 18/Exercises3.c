// Viết hàm tính tổng ba số thực và gán kết quả vào sum,
// hàm trả về void.
// Viết hàm tính tích ba số nguyên gán kết quả vào prod và trả về void

#include <stdio.h>

/*
 * @author Branium Academy
 */

// hàm tính tổng
void sumOfRealNumbers(float a, float b, float c, float* sum) {
	*sum = a + b + c;
}

// hàm tính tích
void productOfIntegerNumbers(int a, int b, int c, int* prod) {
	*prod = a * b * c;
}

int main() {
	// test
	int a, b, c;
	float x, y, z;
	// gọi hàm nhập ba số
	puts("Nhap vao ba so thuc: ");
	scanf("%f%f%f", &x, &y, &z);
	float sum;
	sumOfRealNumbers(x, y, z, &sum);
	printf("sumOfRealNumbers(%f, %f, %f) = %f\n", x, y, z, sum);

	puts("Nhap vao ba so nguyen: ");
	scanf("%d%d%d", &a, &b, &c);
	int prod;
	productOfIntegerNumbers(a, b, c, &prod);
	printf("productOfIntegerNumbers(%d, %d, %d) = %d\n", a, b, c, prod);

	return 0;
}
