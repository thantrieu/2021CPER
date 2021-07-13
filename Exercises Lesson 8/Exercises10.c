// Nhập vào điểm một sinh viên và cho biết sinh viên
// này được điểm chữ tương ứng là gì?
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	float score; // điểm số
	puts("Nhap diem: ");
	scanf("%f", &score);

	char rank;
	if (score >= 9.0f) { // >= 9.0
		rank = 'A';
	}
	else if (score >= 7.0f) { // 7.0 <= score < 9
		rank = 'B';
	}
	else if (score >= 5.0f) { // 5.0 <= score < 7
		rank = 'C';
	}
	else if (score >= 4.0f) { // 4.0 <= score < 5
		rank = 'D';
	}
	else { // còn lại là dưới 4.0
		rank = 'F';
	}

	printf("Sinh vien dat diem: %c\n", rank);
}