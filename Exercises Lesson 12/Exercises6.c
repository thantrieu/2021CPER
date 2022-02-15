/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braniumacademy.net
*/

#include <stdio.h>

int main() {
	int t; // số lượng bộ test
	int a, b;
	scanf("%d", &t);
	while (t > 0) {
		scanf("%d%d", &a, &b);
		if (a * b <= 0 || a < 0) { // giả định không xét số âm và 2 số có tích bằng 0
			puts("NO");
		}
		else {
			// số nguyên tố cùng nhau là cặp số có ước chung lớn nhất
			// bằng 1
			// tìm ước chung lớn nhất của hai số a, b
			while (a != b) {
				if (a > b) {
					a -= b;
				}
				else {
					b -= a;
				}
			}
			// lúc này a = b nên ta kiểm tra a hoặc b đều ok

			if (a == 1) {
				puts("YES");
			}
			else {
				puts("NO");
			}
		}
		t--;
	}
}