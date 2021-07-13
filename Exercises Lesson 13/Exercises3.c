// Nhập vào hai số nguyên dương a, b sao cho a < b. Nhập số n, liệt kê tối đa
// n số chính phương trong đoạn [a, b]
// số chính phương là nguyên có căn bậc hai là số tự nhiên

#include <stdio.h>
#include <math.h>

/*
* @author Branium Academy
*/

int main() {
	int a, b, n;
	puts("Nhap hai so nguyen a, b sao cho a < b:");
	scanf("%d%d", &a, &b);
	printf("Nhap n: ");
	scanf("%d", &n);
	
	if (a >= 0 && b >= 0) {
		int i;	 // biến chạy
		int count = 0; // biến đếm các số chính phương tìm được
		int bound = sqrt(b); // giới hạn trên
		for (i = sqrt(a); i <= bound; i++) {
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