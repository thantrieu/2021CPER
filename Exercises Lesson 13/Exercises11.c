// Vẽ hình trái tim bằng các dấu * trong phạm vi kích thước 6 x 7

#include <stdio.h>

/*
* @author Branium Academy
*/

int main() {
	int i, j;
	for (i = 1; i < 7; i++) {
		for (j = 1; j <= 7; j++) { // vẽ trên 6 hàng
			// chỉ in ra * ở hàng đầu, hàng cuối, cột đầu, cột cuối
			if (!(i == 1 && (j == 1 || j == 4 || j == 7) || 
				(i == 4 && (j == 1 || j == 7)) || 
				(i == 5 && (j <= 2 || j >= 6)) || 
				(i == 6 && j != 4))) {
				printf(" * "); // in ra các dấu *
			}
			else { // những vị trí còn lại in dấu cách
				printf("   "); // in ra ba dấu cách
			}
			// dành bao nhiêu kí tự in dấu * thì dành bấy nhiêu kí tự in dấu cách
		}
		printf("\n"); // in xuống dòng
	}
}