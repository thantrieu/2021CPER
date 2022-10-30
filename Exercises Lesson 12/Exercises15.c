/**
 * @file Exercises15.c
 * @author Branium Academy
 * @brief 
 * @version 2.0
 * @date 2022-10-30
 * @see https://braniumacademy.net
 * 
 * @copyright Copyright (c) Branium Academy 2022
 * 
 */

#include <stdio.h>

int main() {
	int month = 0; // khởi tạo tháng bắt đầu bằng 0
	do {
		puts("Nhap vao thang cua nam(1-12).\nNhap 0 de thoat:");
		scanf("%d", &month); // đọc vào tháng ở dạng số
		switch (month) // chia trường hợp
		{
		case 0: // thoát chương trình
			puts("==> Chuong trinh ket thuc.");
			break;
		case 1:
			puts("January");
			break;
		case 2:
			puts("February");
			break;
		case 3:
			puts("March");
			break;
		case 4:
			puts("April");
			break;
		case 5:
			puts("May");
			break;
		case 6:
			puts("June");
			break;
		case 7:
			puts("July");
			break;
		case 8:
			puts("August");
			break;
		case 9:
			puts("September");
			break;
		case 10:
			puts("October");
			break;
		case 11:
			puts("November");
			break;
		case 12:
			puts("December");
			break;
		default: // trường hợp ngoại lệ
			puts("ERROR");
			break;
		}
	} while (month != 0); // lặp đi lặp lại chừng nào month còn khác 0
}
