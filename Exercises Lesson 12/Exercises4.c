/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braniumacademy.net
*/

#include <stdio.h>
#include <math.h> // sử dụng hàm tính căn bậc hai

int main() {
	int t; // số lượng bộ test
	int n;
	scanf("%d", &t);
	int counter = 1;
	while (t > 0) {
		scanf("%d", &n);
		if (n < 2) {
			printf("Test %d: NO\n", counter);
		}
		else {
			// số nguyên tố là số chỉ chia hết cho 1 và chính nó
			// vậy trong đoạn từ 2 đến căn bậc hai của nó
			// mà tồn tại ước số của nó => không phải số nguyên tố
			int i = 2;
			int isPrime = 1;
			int bound = (int)sqrt(n); // lấy phần nguyên căn bậc hai
			while (i <= bound) {
				if (n % i == 0) {
					isPrime = 0; // đánh dấu n không nguyên tố
					break; // kết thúc vòng lặp
				}
				i++;
			}
			// lúc này đã có kết quả kiểm tra
			if (isPrime) {
				printf("Test %d: YES\n", counter);
			}
			else {
				printf("Test %d: NO\n", counter);
			}
		}
		t--;
		counter++;
	}
}
