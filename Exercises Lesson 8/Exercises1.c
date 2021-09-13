// Nhập vào một số nguyên n và kiểm tra n chẵn hay lẻ
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap n: ");
	scanf("%d", &n); // đọc n vào
	// kiểm tra
	if (n % 2 == 0) { // n chia hết cho 2 thì n là số chẵn
		printf("EVEN\n"); // \n để in xuống dòng mới
	}
	else { // ngược lại n là số lẻ
		printf("ODD\n");
	}
}