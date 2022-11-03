// Viết hàm thực hiện các chức năng sau:
// tính tổng các chữ số của tổng a + b trả về int
// đếm các chữ số lẻ của tổng a + b trả về int
// tính trung bình cộng các chữ số của tích và trả về float

#include <stdio.h>

/*
 * @author Branium Academy
 */

// hàm tính tổng các chữ số của tổng
int sumOfDigits(int a, int b, int* sum) {
	*sum = 0; // đưa giá trị mặc định ban đầu về 0
	int s = a + b;
	while (s > 0) {
		*sum += s % 10;
		s /= 10;
	}
	return *sum;
}

// hàm đếm các số lẻ của tổng
int countOddNumbers(int a, int b, int* counter) {
	*counter = 0;// giả sử ban đầu count có giá trị là 5
	int s = a + b;
	int c;
	while (s > 0) {
		c = s % 10; // lấy phần đơn vị của s
		s /= 10; // bỏ đi phần đơn vị
		if (c % 2 != 0) { // nếu chữ số đang xét là lẻ
			(*counter)++; // tăng biến đếm số chữ số lẻ
		}
	}
	return *counter; // trả về kết quả tìm đc
}

// hàm tính trung bình cộng các chữ số của tích
float avgDigits(int a, int b, float* avg) {
	int prod = a * b;
	int count = 0; // dùng để đếm các chữ số hiện có trong prod
	int sum = 0;
	while (prod > 0) {
		sum += prod % 10; // cộng dồn phần đơn vị của prod
		prod /= 10; // bỏ đi phần đơn vị
		count++; // tăng biến đếm số chữ số lên
	}
	if (count > 0) { // nếu số chữ số có nghĩa > 0
		*avg = (float)sum / count;
	}
	else {
		*avg = 0;
	}
	return *avg;
}
 
int main() {
	// test
	int a, b;
	puts("Nhap vao 2 so nguyen: ");
	scanf("%d%d", &a, &b);
	
	if (a >= 0 && b >= 0) {
		int sum;
		int oddNumber;
		float avg;

		printf("Tong cac chu so cua tong: %d\n", sumOfDigits(a, b, &sum));
		printf("So chu so le cua tong: %d\n", countOddNumbers(a, b, &oddNumber));
		printf("Trung binh cong cac chu so cua tich: %f\n", avgDigits(a, b, &avg));
	}
	else {
		printf("Vui long nhap hai so nguyen > 0");
	}

	return 0;
}
