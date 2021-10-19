/*
 * @author Branium Academy
 * @version 2021.10
 * @see https://braniumacademy.net
*/
#include <stdio.h>

int main() {
	char rank;
	puts("Nhap ki tu a, b, c, d, f: ");
	scanf("%c", &rank);

	switch (rank)
	{
	case 'a': // loại giỏi
	case 'A':
		puts("Gioi");
		break;
	case 'b': // loại khá
	case 'B':
		puts("Kha");
		break;
	case 'c': // loại trung bình
	case 'C':
		puts("Trung binh");
		break;
	case 'd': // loại yếu
	case 'D':
		puts("Yeu");
		break;
	case 'f': // trượt môn
	case 'F':
		puts("Liet");
		break;
	default:
		puts("INVALID");
		break;
	}
}