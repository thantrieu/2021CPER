/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braniumacademy.net
*/

#include <stdio.h>

int main() {
	int choice; // lưu các lựa chọn
	do {
		puts("Nhap thang (1-12).\nNhap 0 de thoat: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			puts("==> Chuong trinh ket thuc.");
			break;
		case 1: // tháng 1
			printf("January");
			break;
		case 2: // tháng 2
			printf("February");
			break;
		case 3: // tháng 3
			printf("March");
			break;
		case 4: // tháng 4
			printf("April");
			break;
		case 5: // tháng 5
			printf("May");
			break;
		case 6: // tháng 6
			printf("June");
			break;
		case 7: // tháng 7
			printf("July");
			break;
		case 8: // tháng 8
			printf("August");
			break;
		case 9: // tháng 9
			printf("September");
			break;
		case 10: // tháng 10
			printf("October");
			break;
		case 11: // tháng 11
			printf("November");
			break;
		case 12: // tháng 12
			printf("December");
			break;
		default:
			puts("Thang khong hop le. Vui long kiem tra lai.");
			break;
		}
		puts("\n==============================");
	} while (choice != 0);
}