// Nhập vào hai số nguyên a, b kiểm tra xem 
// hai số đó bằng nhau hay khác nhau bao nhiêu đơn vị
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int a, b;
	puts("Nhap hai so nguyen a, b: ");
	scanf("%d%d", &a, &b);
	// kiểm tra
	if (a == b) { // hai số bằng nhau
		puts("Hai so bang nhau");
	}
	else { // hai số khác nhau
		int dif = a - b; // lấy độ chênh lệch
		if (dif < 0) { // nếu là số âm
			dif = -dif; // đổi dấu
		}
		printf("Hai so khac nhau %d don vi.\n", dif);
	}
}
