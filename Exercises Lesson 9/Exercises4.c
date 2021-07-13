// Nhập vào một kí tự a, b, c, d, f
// hiển thị kết quả xếp loại học tập tương ứng
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	char rank;
	puts("Nhap ki tu a, b, c, d, f: ");
	scanf("%c", &rank);

	switch (rank)
	{
	case 'a': // loại giỏi
	case 'A':
		printf("Gioi");
		break;
	case 'b': // loại khá
	case 'B':
		printf("Kha");
		break;
	case 'c': // loại trung bình
	case 'C':
		printf("Trung binh");
		break;
	case 'd': // loại yếu
	case 'D':
		printf("Yeu");
		break;
	case 'f': // trượt môn
	case 'F':
		printf("Liet");
		break;
	default:
		puts("Sai tuy chon. Vui long kiem tra lai");
		break;
	}
}