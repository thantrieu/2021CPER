// Nhập số nguyên dương n sau đó kiểm tra xem
// n có phải số nguyên tố hay không
#include <stdio.h>
#include <math.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen n > 0: ");
	scanf("%d", &n);

	// số nguyên tố là số chỉ chia hết cho 1 và chính nó.
	// số n không nguyên tố luôn có nghiệm trong đoạn [2, căn bậc hai của n]
	// vậy ta chỉ cần tìm ra một ước trong đoạn chứa nghiệm
	// khác 1 và chính nó, tức là từ 2 đến căn bậc hai của n
	// thì ta sẽ kết luận n không phải số nguyên tố
	if (n < 2) { // mọi số nguyên < 2 không là số nguyên tố
		printf("%d khong phai so nguyen to", n);
	}
	else {
		int i;
		int isPrime = 1;
		for (i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				//nếu tồn tại nghiệm -> n không phải số ng.tố
				isPrime = 0; // đánh dấu lại
				break; // kết thúc việc kiểm tra
			}
		}
		if (isPrime) {
			printf("%d la so nguyen to\n", n);
		}
		else {
			printf("%d khong phai so nguyen to.\n", n);
		}
	}
}