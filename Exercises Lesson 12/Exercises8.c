/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braniumacademy.net
*/

#include <stdio.h>
#include <math.h>

int main() {
	int t, a, b;
	scanf("%d", &t);
	while (t > 0) {
		scanf("%d%d", &a, &b);
		if (a > b) {
			printf("\n");
		}
		else {
			for (int i = a; i <= b; i++) {
				int isPrime = 1;
				if (i < 2) {
					isPrime = 0;
				}
				int bound = (int)sqrt(i);
				int j = 2;
				while (j <= bound) {
					if (i % j == 0) {
						isPrime = 0;
					}
					j++;
				}
				if (isPrime == 1) {
					printf("%d ", i);
				}
			}
			printf("\n");
		}
		t--;
	}
}
