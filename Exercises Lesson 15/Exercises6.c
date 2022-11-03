/**
* @author Branium Academy
* @version 2022.10.09
* @see https://braniumacademy.net
*/

#define _CRT_SECURE_NO_WARNINGS // bỏ dòng này đi nếu không dùng visual studio
#include <stdio.h>

void printTotal(int amount) {
	printf("%s\n", "Thanh tien");
	printf("%-45s%-30d\n", "Tien dien chua thue: ", amount);
	printf("%-45s%-30d\n", "Thue GTGT (8%%) tien dien: ", (int)(amount * 0.08));
	printf("%-45s%-30d\n", "Tong cong tien thanh toan(dong): ", (int)(amount * 1.08));
}

void feeAllLevel(int kwh) {
	int totalAmount = 0;
	if (kwh <= 50) {
		totalAmount += feePerLevel(1, 1678, kwh) + feePerLevel(2, 1734, 0)
			+ feePerLevel(3, 2014, 0) + feePerLevel(4, 2536, 0)
			+ feePerLevel(5, 2834, 0) + feePerLevel(6, 2927, 0);
	} else if (kwh <= 100) {
		totalAmount += feePerLevel(1, 1678, 50) + feePerLevel(2, 1734, kwh - 50)
			+ feePerLevel(3, 2014, 0) + feePerLevel(4, 2536, 0)
			+ feePerLevel(5, 2834, 0) + feePerLevel(6, 2927, 0);
	}
	else if (kwh <= 200) {
		totalAmount += feePerLevel(1, 1678, 50) + feePerLevel(2, 1734, 50)
			+ feePerLevel(3, 2014, kwh - 100) + feePerLevel(4, 2536, 0)
			+ feePerLevel(5, 2834, 0) + feePerLevel(6, 2927, 0);
	}
	else if (kwh <= 300) {
		totalAmount += feePerLevel(1, 1678, 50) + feePerLevel(2, 1734, 50)
			+ feePerLevel(3, 2014, 100) + feePerLevel(4, 2536, kwh - 200)
			+ feePerLevel(5, 2834, 0) + feePerLevel(6, 2927, 0);
	}
	else if (kwh <= 400) {
		totalAmount += feePerLevel(1, 1678, 50) + feePerLevel(2, 1734, 50)
			+ feePerLevel(3, 2014, 100) + feePerLevel(4, 2536, 100)
			+ feePerLevel(5, 2834, kwh - 300) + feePerLevel(6, 2927, 0);
	}
	else {
		totalAmount += feePerLevel(1, 1678, 50) + feePerLevel(2, 1734, 50)
			+ feePerLevel(3, 2014, 100) + feePerLevel(4, 2536, 100)
			+ feePerLevel(5, 2834, 100) + feePerLevel(6, 2927, kwh - 400);
	}
	printTotal(totalAmount);
}

void printData(int level, int price, int kwh, int amount) {
	printf("Bac thang %-5d%-30d%-15d%-15d\n", level, price, kwh, amount);
}

int feePerLevel(int level, int amount, int kwh) {
	printData(level, amount, kwh, amount * kwh);
	return amount * kwh;
}

int main() {
	int kwhValue;
	printf("So kwh da su dung: ");
	scanf("%d", &kwhValue);
	printf("%-15s%-30s%-15s%-15s\n", "", "DON GIA THEO QD 648/QD-BCT", "SAN LUONG", "THANH TIEN");
	printf("%-15s%-30s%-15s%-15s\n", "", "(dong/kWh)", "(kWh)", "(dong)");
	feeAllLevel(kwhValue);
	return 0;
}
