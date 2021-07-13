// Nhập vào hai số nguyên a, b sao cho a < b. Liệt kê tối đa
// 2 số nguyên tố trong đoạn [a, b]

#include <stdio.h>
#include <math.h>

/*
* @author Branium Academy
*/

int main() {
	int a, b;
	puts("Nhap hai so nguyen a, b sao cho a < b:");
	scanf("%d%d", &a, &b);

	// biến lưu trạng thái kiểm tra số nguyên tố
	int isPrime; // biến đánh dấu xem giá trị đang xét có là số ng.tố
	int i, j;	 // biến chạy
	int count = 0; // biến đếm các số nguyên tố tìm được

	for (i = a; i <= b; i++) {
		isPrime = 1;
		if (i < 2) { // mọi giá trị nguyên < 2 không phải số nguyên tố
			isPrime = 0;
		}
		else {
			int bound = sqrt(i); // lấy căn bậc hai củai
			for (j = 2; j <= bound; j++) {
				if (i % j == 0) { // nếu i có ước khác 1 và chính nó
					isPrime = 0; // i không phải ng.tố
					break; // thoát vòng lặp
				}
			}
		}
		// dựa vào giá trị biến isPrime để đưa ra kết luận
		if (isPrime) {
			printf("%d ", i);
			count++;
			if (count == 2) {
				break; // kết thúc
			}
		}
	}
	if (count == 0) {
		printf("Khong co so nguyen to trong doan [%d, %d]", a, b);
	}
}