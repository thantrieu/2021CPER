// Phân tích số nguyên dương n thành các thừa số nguyên tố của nó
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen duong n: ");
	scanf("%d", &n);
	if (n <= 0) {
		puts("Vui long nhap so nguyen duong n");
	}
	else {
		// số nguyên tố bắt đầu từ 2, ta cho i chạy từ 2.
		// nếu n chia hết cho i thì in ra i và giảm n đi i lần
		// nếu không thì tăng i lên
		// lặp lại chừng nào n còn lớn hơn 1
		printf("%d = ", n);
		int i = 2;
		while (n > 1) {
			if (n % i == 0) {
				printf("%d", i);
				if (n != i) { // nếu chưa phải số nguyên tố cuối cùng,
					printf(" x "); // thì in ra dấu x
				}
				n /= i; // giảm n đi i lần
			}
			else { // ngược lại tăng i lên
				i++;
			}
		}
	}
}