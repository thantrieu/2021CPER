/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braniumacademy.net
*/

#include <stdio.h>
#include <math.h>

int main() {
	int t, a, b, k;
	scanf("%d", &t);
	while (t > 0) {
		scanf("%d%d%d", &a, &b, &k);
		if (a > b || k > b) {
			printf("\n"); // không có kết quả
		}
		else {
			int i = a;
			while (i <= b) {
				if (i % k == 0) {
					printf("%d ", i);
				}
				i++;
			}
			printf("\n");
		}
		t--;
	}
}
