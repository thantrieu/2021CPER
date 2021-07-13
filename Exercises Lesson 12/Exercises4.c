// Nhập số nguyên dương n và kiểm tra xem n có phải là
// số nguyên tố hay không
#include <stdio.h>
#include <math.h> // sử dụng hàm căn bậc hai
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen duong n: ");
	scanf("%d", &n);
	if (n < 2) {
		puts("Khong la so nguyen to");
	}
	else {
		// số nguyên tố là số chỉ chia hết cho 1 và chính nó
		// vậy trong đoạn từ 2 đến căn bậc hai của nó
		// mà tồn tại ước số của nó => không phải số nguyên tố
		int i = 2;
		int isPrime = 1;
		int bound = sqrt(n); // lấy phần nguyên căn bậc hai
		while (i <= bound) {
			if (n % i == 0) {
				isPrime = 0; // đánh dấu n không nguyên tố
				break; // kết thúc vòng lặp
			}
			i++;
		}
		// lúc này đã có kết quả kiểm tra
		if (isPrime) {
			printf("%d la so nguyen to\n", n);
		}
		else {
			puts("Khong la so nguyen to");
		}
	}
}