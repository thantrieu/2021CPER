/**
 * @file Exercises8.c
 * @author Branium Academy
 * @brief 
 * @version 3.0
 * @date 2023-01-15
 * @see https://braniumacademy.net
 * 
 * @copyright Copyright (c) Branium Academy 2023
 * 
 */

#include <stdio.h>
#include <math.h>

int main() {
	int t, a, b;
	int testIndex = 1;
	scanf("%d", &t);
	while (testIndex <= t) {
		scanf("%d%d", &a, &b);
		printf("Test %d:\n", testIndex);
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
		testIndex++;
	}
}
