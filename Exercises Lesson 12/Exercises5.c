/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braniumacademy.net
*/

#include <stdio.h>

int main() {
	int t; // số bộ test
	int n; // số n cần tính n!
	scanf("%d", &t);
	while (t > 0) {
		scanf("%d", &n); // đọc vào số n
		if (n < 0 || n > 23) { // n không hợp lệ
			puts("ERROR");
		}
		else { // n hợp lệ
			unsigned long long factorial = 1;
			int i = 2;
			while (i <= n) { // tính n!
				factorial *= i;
				i++;
			}
			printf("%llu\n", factorial); // hiển thị kết quả
		}
		t--;
	}
}