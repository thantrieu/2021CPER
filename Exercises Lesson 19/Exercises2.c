// Viết hàm thực hiện các chức năng sau:
// sinh số ngẫu nhiên trong đoạn [1, n], chương trình
// kết thúc khi giá trị nhập vào trùng với giá trị sinh ra
// đếm xem người dùng đã nhập vào bao nhiêu giá trị từ khi
// bắt đầu chương trình.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * @author Branium Academy
 */

// hàm sinh số ngẫu nhiên trong đoạn [a, b]
int randomNumber(int n) {
	int num = rand() % n + 1;
	return num;
}

int main() {
	srand(time(NULL)); // hàm gieo quẻ
	int n;
	puts("Nhap so nguyen duong n: ");
	scanf("%d", &n);
	// điều kiện để thực hiện chương trình
	if (n > 0) {
		int count = 0;
		while (1) {
			count++;
			int guessNumber;
			puts("Nhap vao con so ban du doan: ");
			scanf("%d", &guessNumber);
			int result = randomNumber(n); // sinh số ngẫu nhiên
			printf("So random = %d\n", result);
			if (guessNumber == result) { // nếu người dùng đoán đúng
				printf("Ban da du doan chinh xac!\nSo lan du doan cua ban: %d\n", count);
				break; // kết thúc chương trình
			}
		}
	}
	else {
		puts("Nhap hai so nguyen duong n");
	}

	return 0;
}