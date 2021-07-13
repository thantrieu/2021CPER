// Giải biện luận phương trình bậc nhất ax + b = 0
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	float a, b; // hệ số a, b
	puts("Nhap he so a, b: ");
	scanf("%f%f", &a, &b);
	
	// TH1: nếu a = 0, b # 0 thì phương trình không có nghiệm
	if (a == 0 && b != 0) {
		puts("Phuong trinh khong co nghiem.");
	}
	// TH2: nếu a = 0, b = 0 thì phương trình vô số nghiệm
	else if (a == 0 && b == 0) { 
		puts("Phuong trinh co vo so nghiem.");
	} 
	// TH3: phương trình có 1 nghiệm x = -b / a
	else{
		float x; // nghiệm phương trình
		x = -b / a;
		printf("Nghiem phuong trinh la: x = %f\n", x);
	}
}