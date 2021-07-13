// Nhập vào hai số thực và thực hiện các chức năng
// cộng trừ nhân chia
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	float a, b; // hai số thực
	puts("Nhap hai so thuc: ");
	scanf("%f%f", &a, &b);

	int choice; // lưu các lựa chọn
	puts("Chon cac chuc nang: ");
	puts("1. Cong");
	puts("2. Tru");
	puts("3. Nhan");
	puts("4. Chia");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1: // thực hiện phép cộng
		printf("%f + %f = %f\n", a, b, a + b);
		break;
	case 2: // thực hiện phép trừ
		printf("%f - %f = %f\n", a, b, a - b);
		break;
	case 3: // thực hiện phép nhân
		printf("%f * %f = %f\n", a, b, a * b);
		break;
	case 4: // thực hiện phép chia
		if (b == 0) { // không thể chia nếu mẫu số = 0
			puts("Khong the thuc hien phep chia");
		} else{
			printf("%f / %f = %f\n", a, b, a / b);
		}
		break;
	default:
		puts("Sai chuc nang. Vui long kiem tra lai");
		break;
	}
}