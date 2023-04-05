// Viết hàm nguyên mẫu và định nghĩa hàm cho các chức năng sau:
// nhập vào hai số thực và trả về void
// nhập vào hai số nguyên và trả về void
// tìm ước chung lớn nhất của hai số nguyên a, b trả về void
// tính giá trị đa thức bậc 3 hệ số thực lưu kết quả vào biến kiểu thực
// và trả về float

#include <stdio.h>

/*
 * @author Branium Academy
*/

// hàm nhập vào hai giá trị kiểu số thực trả về void
void getRealNumbers(float* a, float* b);

// hàm nhập vào hai giá trị số nguyên và trả về kiểu void
void getIntegerNumbers(int* a, int* b);

// hàm tìm ước chung lớn nhất của hai số nguyên
int gcd(int a, int b);

// hàm tính giá trị đa thức bậc 3 trả về float
float valueOfPolynomial(float a, float b, float c, float x, float* result);

int main() {
	float a, b;
	int x, y;
	// gọi hàm nhập hai số thực
	getRealNumbers(&a, &b);
	// gọi hàm nhập hai số nguyên
	getIntegerNumbers(&x, &y);
	// gọi hàm tìm ước chung:
	if (x < 0 && y < 0) {
		puts("Nhap hai so nguyen > 0");
	}
	else {
		printf("UCLN = %d\n", gcd(x, y));
	}
	// gọi hàm tính giá trị đa thức
	// bạn hãy thay thế các tham số theo mong muốn
	float res;
	valueOfPolynomial(a, b, 5, 2, &res);
	printf("Gia tri cua bieu thuc: %f\n", res);

	return 0;
}

// phần định nghĩa hàm
void getRealNumbers(float* a, float* b) {
	puts("Nhap hai so thuc: ");
	scanf("%f%f", a, b);
}

void getIntegerNumbers(int* a, int* b) {
	puts("Nhap hai so nguyen: ");
	scanf("%d%d", a, b);
}

int gcd(int a, int b) {
	if (a == 0 && b == 0) {
		puts("Khong co uoc chung lon nhat");
		return -1;
	}
	else if (a == 0) {
		return b;
	}
	else if (b == 0) {
		return a;
	}
	else { // a, b đều khác 0
		while(a != b) {
			if (a > b) {
				a -= b;
			}
			else {
				b -= a;
			}
		}
		return a;
	}
}

float valueOfPolynomial(float a, float b, float c, float x, float* result) {
	*result = x * x * x + a * x * x + b * x + c;
	return (*result);
}