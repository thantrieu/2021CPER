/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braiumacademy.net
*/
#include <stdio.h>

int main() {
	int t; // số bộ test
	int n; // số cần phân tích ra thừa số
	scanf("%d", &t);
	while (t > 0) {
		scanf("%d", &n);
		if (n <= 0) {
			puts("ERROR");
		}
		else {
			// số nguyên tố bắt đầu từ 2, ta cho i chạy từ 2.
			// nếu n chia hết cho i thì in ra i và giảm n đi i lần
			// nếu không thì tăng i lên
			// lặp lại chừng nào n còn lớn hơn 1
			int i = 2;
			while (n > 1) {
				if (n % i == 0) {
					printf("%d", i);
					if (n != i) { // nếu chưa phải số nguyên tố cuối cùng,
						printf(" x "); // thì in ra dấu x
					}
					else {
						printf("\n");
					}
					n /= i; // giảm n đi i lần
				}
				else { // ngược lại tăng i lên
					i++;
				}
			}
		}
		t--;
	}
}