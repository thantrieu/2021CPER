/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braniumacademy.net
*/

#include <stdio.h>

int main() {
	int choice; // lưu các lựa chọn
	do {
		puts("Nhap ngay (1-7).\nNhap 0 de thoat: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			puts("==> Chuong trinh ket thuc.");
			break;
		case 1: // thứ hai
			printf("Monday");
			break;
		case 2: // thứ ba
			printf("Tuesday");
			break;
		case 3: // thứ tư
			printf("Wednesday");
			break;
		case 4: // thứ năm
			printf("Thursday");
			break;
		case 5: // thứ sáu
			printf("Friday");
			break;
		case 6: // thứ bảy
			printf("Saturday");
			break;
		case 7: // chủ nhật
			printf("Sunday");
			break;
		default:
			puts("Gia tri khong hop le. Vui long kiem tra lai!");
			break;
		}
		puts("\n==============================");
	} while (choice != 0);
}