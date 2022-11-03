// Viết chương trình nhập vào ngày tháng năm với định dạng
// dd/mm/yyyy và tính tổng các chữ số của ngày tháng năm sinh
// chương trình cần chạy đúng trong các trường hợp khác nhau
// của kí tự phân tách giữa ngày-tháng-năm

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập ngày tháng năm
void getDateTime(int* day, int* month, int* year);
// hàm hiển thị kết quả
void showResult(int day, int month, int year);
// hàm kiểm tra ngày tháng năm có hợp lệ không
int isCorrect(int day, int month, int year);

int main() {
	int day, month, year;
	getDateTime(&day, &month, &year);
	if (!isCorrect(day, month, year)) {
		puts("Nhap dung ngay thang nam");
	}
	else {
		showResult(day, month, year);
	}

	return 0;
}

int isCorrect(int day, int month, int year) {
	if (day < 0 || month < 0 || month > 12
		|| year < 1930 || year > 2050) {
		return 0;
	}
	else {
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day <= 31) {
				return 1;
			}
			break;
		case 2:
			if (day <= 29) { // giả sử quy ước tháng 2 29 ngày
				return 1;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day <= 30) {
				return 1;
			}
			break;
		default:
			break;
		}
		return 0;
	}
}

void getDateTime(int* day, int* month, int* year) {
	puts("Nhap vao ngay thang nam: ");
	scanf("%d%*c%d%*c%d", day, month, year);
}

void showResult(int day, int month, int year) {
	int sumDigits(int n);
	int sum = 0;
	sum += sumDigits(day);
	sum += sumDigits(month);
	sum += sumDigits(year);
	printf("Tong cac chu so cua ngay-thang-nam: %d\n", sum);
}

int sumDigits(int n) {
	int s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}