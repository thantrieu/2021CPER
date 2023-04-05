/*
 * @author Branium Academy
 * @version 2022.02.15
 * @see https://braniumacademy.net
*/

#include <stdio.h>

int main() {
	int choice; // lưu các lựa chọn
	do {
		puts("Nhap so khac 0 de tiep tuc.\nNhap 0 de thoat: ");
		scanf("%d", &choice);

		if (!choice) { // nếu nhập 0
			break; // thoát
		}
		// ngược lại tiếp tục chương trình
		int day, month; // ngày sinh tháng sinh
		puts("Nhap ngay sinh: ");
		scanf("%d", &day); // đọc vào ngày sinh

		puts("Nhap thang sinh: ");
		scanf("%d", &month); // đọc vào tháng sinh

		switch (month)
		{
		case 1:
			if (day >= 1 && day < 20) { // 1 - 19/1
				puts("Ma Ket");
			}
			else if (day >= 20 && day <= 31) { // 20 - 31/1
				puts("Bao Binh");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 2:
			if (day >= 1 && day < 19) { // 1 - 18/2
				puts("Bao Binh");
			}
			else if (day >= 19 && day <= 29) { // 19 - 29/2
				puts("Song Ngu");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 3:
			if (day >= 1 && day < 21) { // 1 - 20/3
				puts("Song Ngu");
			}
			else if (day >= 21 && day <= 31) { // 21 - 31/3
				puts("Bach Duong");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 4:
			if (day >= 1 && day < 21) { // 1 - 20/4
				puts("Bach Duong");
			}
			else if (day >= 21 && day <= 30) { // 21 - 30/4
				puts("Kim Nguu");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 5:
			if (day >= 1 && day < 21) { // 1 - 20/5
				puts("Kim Nguu");
			}
			else if (day >= 21 && day <= 31) { // 21 - 31/5
				puts("Song Tu");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 6:
			if (day >= 1 && day < 22) { // 1 - 21/6
				puts("Song Tu");
			}
			else if (day >= 22 && day <= 30) { // 22 - 30/6
				puts("Cu Giai");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 7:
			if (day >= 1 && day < 23) { // 1 - 22/7
				puts("Cu Giai");
			}
			else if (day >= 23 && day <= 31) { // 23 - 31/7
				puts("Su Tu");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 8:
			if (day >= 1 && day < 23) { // 1 - 22/8
				puts("Su Tu");
			}
			else if (day >= 23 && day <= 31) { // 23 - 31/8
				puts("Xu Nu");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 9:
			if (day >= 1 && day < 23) { // 1 - 22/9
				puts("Xu Nu");
			}
			else if (day >= 23 && day <= 30) { // 23 - 30/9
				puts("Thien Binh");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 10:
			if (day >= 1 && day < 24) { // 1 - 23/10
				puts("Thien Binh");
			}
			else if (day >= 24 && day <= 31) { // 24 - 31/10
				puts("Bo Cap");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 11:
			if (day >= 1 && day < 23) { // 1 - 22/11
				puts("Bo Cap");
			}
			else if (day >= 23 && day <= 30) { // 23 - 30/11
				puts("Nhan Ma");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		case 12:
			if (day >= 1 && day < 22) { // 1 - 21/12
				puts("Nhan Ma");
			}
			else if (day >= 22 && day <= 31) { // 22 - 31/12
				puts("Ma Ket");
			}
			else {
				puts("==> Ngay khong hop le.");
			}
			break;
		default:
			puts("==> Thang khong hop le.");
			break;
		}
		puts("\n==============================");
	} while (choice != 0);

	puts("==> Chuong trinh ket thuc.");
}