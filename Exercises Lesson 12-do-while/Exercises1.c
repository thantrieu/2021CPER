/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braniumacademy.net
*/
#include <stdio.h>
#include <math.h>

int main() {
	int a, b;
	puts("Nhap hai so nguyen a, b: ");
	scanf("%d%d", &a, &b);

	int choice; // lưu các lựa chọn
	do {
		puts("Chon cac chuc nang: ");
		puts("1. Cong hai so");
		puts("2. Tru a cho b");
		puts("3. Nhan a voi b");
		puts("4. Chia a cho b");
		puts("5. Chia lay du a cho b");
		puts("6. Tinh a^b, b >= 0");
		puts("0. Thoat");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			puts("Xin chao va hen gap lai");
			break;
		case 1: // thực hiện phép cộng
			printf("%d + %d = %d\n", a, b, a + b);
			break;
		case 2: // thực hiện phép trừ
			printf("%d - %d = %d\n", a, b, a - b);
			break;
		case 3: // thực hiện phép nhân
			printf("%d * %d = %d\n", a, b, a * b);
			break;
		case 4: // thực hiện phép chia
			if (b == 0) { // không thể chia nếu mẫu số = 0
				puts("Khong the thuc hien phep chia");
			}
			else {
				printf("%d / %d = %f\n", a, b, (float)a / b);
			}
			break;
		case 5: // thực hiện phép chia
			if (b == 0) { // không thể chia nếu mẫu số = 0
				puts("Khong the thuc hien phep chia");
			}
			else {
				printf("%d %% %d = %d\n", a, b, a % b);
			}
			break;
		case 6:
			// ép kiểu sang int
			printf("%d^%d = %d\n", a, b, (int)pow(a, b));
			break;
		default:
			puts("Sai chuc nang. Vui long kiem tra lai");
			break;
		}
		puts("\n==============================");

	} while (choice != 0);
}