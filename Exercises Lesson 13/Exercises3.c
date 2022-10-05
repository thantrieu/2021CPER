// Nhập vào hai số nguyên dương a, b sao cho a < b. Nhập số n, liệt kê tối đa
// n số chính phương trong đoạn [a, b]
// số chính phương là nguyên có căn bậc hai là số tự nhiên

// Nếu dùng Visual Studio thì thêm dòng sau:
#define _CRT_SECURE_NO_WARNINGS // không dùng Visual Studio thì xóa bỏ dòng này đi
#include <stdio.h>
#include <math.h>

/*
* @author Branium Academy
* @version 2022.10.05
* @see https://braniumacademy.net
*/

int main() {
	int a, b, n;
	puts("Nhap hai so nguyen a < b:");
	scanf("%d%d", &a, &b);
	printf("Nhap so nguyen n > 0: ");
	scanf("%d", &n);
	if (n <= 0) {
		puts("Vui long nhap n > 0.");
	}
	else {
		if (a >= 0 && b >= 0) {
			int i;	 // biến chạy
			int count = 0; // biến đếm các số chính phương tìm được
			int bound = (int)sqrt(b); // giới hạn trên, ép kiểu sang int
			for (i = (int)sqrt(a); i <= bound; i++) {
				if (i * i >= a) {
					printf("%d ", i * i);
					count++;
					if (count == n) {
						break; // kết thúc
					}
				}
			}
			if (count == 0) {
				printf("Khong co so chinh phuong trong doan [%d, %d]", a, b);
			}
		}
		else {
			puts("Nhap hai so nguyen duong a, b sao cho a < b");
		}
	}
}