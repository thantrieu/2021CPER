// Viết hàm thực hiện chương trình "Game Of Crafts"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * @author Branium Academy
 */

// hàm sinh số ngẫu nhiên trong đoạn [1, 6]
int rollDice();

int main() {
	// enum lưu trạng thái trò chơi của người chơi
	enum Status { WON, LOSE, CONTINUE };
	srand(time(NULL)); // hàm gieo quẻ
	
	// khai báo biến lưu điểm và trạng thái người chơi
	enum Status gameStatus;
	int myPoint;

	// người chơi bắt đầu chơi
	int sum = rollDice();

	// xét các trường hợp từ kết quả nhận được: 
	switch (sum)
	{
		// trường hợp người chơi thắng
	case 7:
	case 11:
		gameStatus = WON;
		break;
		// trường hợp người chơi thua
	case 2:
	case 3:
	case 12:
		gameStatus = LOSE;
		break;
		// các trường hợp còn lại người chơi tiếp tục chơi
	default:
		myPoint = sum;
		gameStatus = CONTINUE;
		printf("Diem cua ban la: %d\n", myPoint);
		break;
	}

	// cho người chơi tiếp tục nếu còn lượt
	while (CONTINUE == gameStatus) {
		sum = rollDice();
		if (sum == 7) { // nếu tung được 7 thì thua
			gameStatus = LOSE;
		}
		else if (sum == myPoint) { // thắng
			gameStatus = WON;
		}
	}

	// Kiểm tra xem người chơi đã thua hay thắng
	if (WON == gameStatus) {
		puts("BAN THANG");
	}
	else {
		puts("BAN THUA");
	}

	return 0;
}

int rollDice() {
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	printf("Ban tung duoc %d + %d = %d\n", dice1, dice2, dice1 + dice2);
	return dice1 + dice2;
}