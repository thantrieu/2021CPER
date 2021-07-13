// Nhập vào giá trị số nguyên từ 1 đến 7
// hiển thị tên ngày trong tuần tương ứng
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int day;
	puts("Nhap ngay (1-7): ");
	scanf("%d", &day);

	switch (day)
	{
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
		puts("Gia tri khong hop le. Vui long kiem tra lai");
		break;
	}
}