/**
 * @file Exercises16.c
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

int main() {
	int t;
	puts("Nhap so bo test: ");
	scanf("%d", &t);

	int test = 1; // số thứ tự bộ test
	do {
		int n, k;
        scanf("%d%d", &n, &k);
        if(k > 0) {
            if(n < 0) {
                n = -n; // đảo dấu của số n để n luôn dương.
            }
            int sum = 0;
            while(n > 0) { 
                int digit = n % 10;
                n /= 10; // loại bỏ phần đơn vị khỏi n
                if(digit <= k) {
                    sum += digit;
                }
            }
            printf("Test %d: %d\n", test, sum);
        } else {
            printf("Test %d: ERROR\n", test);
        }
        test++;
	} while (test <= t);
}