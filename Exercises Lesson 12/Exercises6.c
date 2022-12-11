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
	int t; // số lượng bộ test
	int a, b;
	scanf("%d", &t);
	while (t > 0) {
		scanf("%d%d", &a, &b);
		if (a * b <= 0 || a < 0) { // giả định không xét số âm và 2 số có tích bằng 0
			puts("NO");
		}
		else {
			int counter1 = 0;
			int counter2 = 0;
			int i = 2;
			// đếm ước khác 1 và chính số a của số a
			while (i < a) {
				if (a % i == 0) {
					counter1++;
				}
				i++;
			}
			// đếm ước khác 1 và chính số b của số b
			i = 2;
			while (i < b) {
				if (b % i == 0) {
					counter2++;
				}
				i++;
			}
			// nếu số ước khác 1 và chính a, b là 0 thì cặp số là nguyên tố
			if (counter2 == counter1 && counter1 == 0) {
				puts("YES");
			}
			else {
				puts("NO");
			}
		}
		t--;
	}
}