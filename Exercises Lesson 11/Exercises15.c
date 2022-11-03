// @author: braniumacademy
// @version: 2021.11
// @see: https://braniumacademy.net

#include <stdio.h>
#include <math.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		int n;
		scanf("%d", &n);
		if (n <= 1) {
			printf("Test %d: NO\n", i);
		}
		else {
			int sum = 1;
			int bound = (int)sqrt(n);
			for (int j = 2; j <= bound; j++)
			{
				if (n % j == 0) {
					sum += j;
					if (j != (n / j)) {
						sum += n / j;
					}
				}
			}
			if (sum == n) {
				printf("Test %d: YES\n", i);
			}
			else {
				printf("Test %d: NO\n", i);
			}
		}
	}
	return 0;
}