// Nhập vào số nguyên n, kiểm tra xem n có nguyên tố hay không
// số nguyên tố là số tự nhiên chỉ chia hết cho 1 và chính nó

#include <stdio.h>
#include <math.h>

/*
* @author Branium Academy
*/

int main() {
	int n;
	puts("Nhap so nguyen n:");
	scanf("%d", &n);

	// biến lưu trạng thái kiểm tra số nguyên tố
	int isPrime = 1; // giả định n là số nguyên tố
	if (n < 2) { // mọi giá trị nguyên < 2 không phải số nguyên tố
		isPrime = 0; 
	}
	else {
		int i;
		int bound = sqrt(n); // lấy căn bậc hai của n
		for (i = 2; i <= bound; i++) {
			if (n % i == 0) { // nếu n có ước khác 1 và chính nó
				isPrime = 0; // n không phải ng.tố
				break; // thoát vòng lặp
			}
		}
	}
	// dựa vào giá trị biến isPrime để đưa ra kết luận
	if (isPrime) {
		printf("La so nguyen to");
	}
	else {
		puts("Khong la so nguyen to");
	}
}