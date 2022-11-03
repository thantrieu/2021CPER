/**
 * @file Exercises15.c
 * @author Branium Academy
 * @brief 
 * @version 2.0
 * @date 2022-10-30
 * @see https://braniumacademy.net
 * 
 * @copyright Copyright (c) Branium Academy 2022
 * 
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
		else if(k == 0) {
			printf("ERROR\n");
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
