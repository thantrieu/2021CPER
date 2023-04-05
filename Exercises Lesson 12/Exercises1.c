/**
 * @file Exercises15.c
 * @author Branium Academy
 * @brief 
 * @version 3.0
 * @date 2023-01-15
 * @see https://braniumacademy.net
 * 
 * @copyright Copyright (c) Branium Academy 2023
 * 
 */

int main() {
	int t, i;
	scanf("%d", &t);
	for(i = 1; i <= t; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if ((a > 0 || b > 0) && a * b >= 0) {
			if(a * b == 0) {
				int result = (a != 0) ? a : b;
				printf("Test %d:\n%d %s\n", i, a, "ERROR");
			} else {
				int tmp = a * b;
			while (a != b) {
				if (a > b) {
					a -= b;
				}
				else {
					b -= a;
				}
			}
			printf("Test %d:\n%d %d\n", i, a, tmp / a);
			}
		}
		else {
			printf("Test %d:\nERROR\n", i);
		}
	}
} 
