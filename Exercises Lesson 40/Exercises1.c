// Viết chương trình nhập vào điểm 3 môn toán, anh, lập trình
// tính TB và hiển thị kế quả làm tròn 2 chữ số sau dấu phẩy

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập vào điểm 
void getGrades(float* math, float* eng, float* prog);
// hàm hiển thị kết quả điểm trung bình
void showAvg(float avg);
// hàm tính trung bình cộng
float avgGrades(float g1, float g2, float g3);

int main() {
	float math, eng, prog;
	getGrades(&math, &eng, &prog);
	float avg = avgGrades(math, eng, prog);
	showAvg(avg);

	return 0;
}

void getGrades(float* math, float* eng, float* prog) {
	printf("Nhap diem ba mon toan, anh, lap trinh: ");
	scanf("%f%f%f", math, eng, prog);
}

void showAvg(float avg) {
	printf("Diem trung binh: %0.2f\n", avg);
}

float avgGrades(float g1, float g2, float g3) {
	return (g1 + g2 + g3) / 3;
}