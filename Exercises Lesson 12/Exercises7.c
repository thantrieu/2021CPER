/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braniumacademy.net
*/

#include <stdio.h>

int main() {
	int t, n;
	scanf("%d", &t);
	int counter = 1;
	while (t > 0) {
		scanf("%d", &n);
		if (n <= 0) {
			printf("Test %d:\nERROR\n", counter);
		}
		else {
			float sum = 0;
			int i = 1;
			while (i <= n) { // thực hiện chừng nào i <= n
				// nhớ ép kiểu sang float
				sum += (float)1 / (i * i * i); // cộng thêm i^3
				i++;
			}
			// lúc này ta đã có kết quả:
			printf("Test %d:\n%0.3f\n", counter, sum); // làm tròn đến 3 chữ số sau dấu phẩy
		}
		t--;
		counter++;
	}
}
