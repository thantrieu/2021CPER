// Viết chương trình nhập vào giờ phút giây ở dạng
// hh:MM:ss sau đó hiển thị kết quả dạng tổng số giây
// chú ý bắt lỗi nhập sai giờ phút giây

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập vào giá trị ở dạng giờ phút giây
void getTime(int* h, int* m, int* s);
// hàm tính và hiển thị ở dạng số giây
void showResult(int h, int m, int s);

int main() {
	int h, m, s;
	getTime(&h, &m, &s);
	showResult(h, m, s);
	return 0;
}

void getTime(int* h, int* m, int* s) {
	puts("Nhap vao thoi gian o dinh dang hh:MM:ss");
	scanf("%d%*c%d%*c%d", h, m, s);
	if (*h < 0 || *h > 23) {
		*h = 0;
		puts("Vui long nhap gio: 0 - 23");
	}
	if (*m < 0 || *m > 59) {
		*m = 0;
		puts("Vui long nhap phut: 0 - 59");
	}
	if (*s < 0 || *s > 59) {
		*s = 0;
		puts("Vui long nhap giay: 0 - 59");
	}
}

void showResult(int h, int m, int s) {
	int totalSec = s + m * 60 + h * 60 * 60;
	printf("Tong so giay: %ds\n", totalSec);
}