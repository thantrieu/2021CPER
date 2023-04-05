/**
 * @file Exercises10.c
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
	int t, n;
	scanf("%d", &t);
	int counter = 1;
	while (t > 0) {
		scanf("%d", &n);
		if(n < 0) {
			n *= -1;
		}
		int other = 0;
		int tmp = n;
		while (tmp > 0) {
			other = other * 10 + tmp % 10;
			tmp /= 10;
		}
		if (n > 9 && n == other) {
			printf("Test %d: YES\n", counter);
		}
		else {
			printf("Test %d: NO\n", counter);
		}
		t--;
		counter++;
	}
}
