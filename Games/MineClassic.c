#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

// hàm nguyên mẫu
void initMap(char** map); // khởi tạo map
void setMine(char** map); // thiết lập vị trí mìn
void initScoreMap(char** map); // khởi tạo điểm
// kiểm tra và đánh dấu ô đã chọn
int checkPoint(char** map, char** result, int x, int y);
void showMap(char** map, char** result, int isOver); // hiển thị map


int main()
{
	int score = 0; // điểm số của người chơi
	char** map; // bản đồ
	char** result; // kết quả
	// cấp phát động
	map = (char**)malloc(sizeof(char*) * SIZE);
	result = (char**)malloc(sizeof(char*) * SIZE);
	int i;
	for (i = 0; i < SIZE; i++)
	{
		map[i] = (char*)malloc(sizeof(char) * SIZE);
		result[i] = (char*)malloc(sizeof(char) * SIZE);
	}
	initMap(map); // khởi tạo map
	initMap(result); // khởi tạo bản đồ vị trí chọn
	setMine(map); // setup vị trí mìn
	initScoreMap(map); // setup điểm

	int x, y;
	while (1) // chơi game
	{
		system("cls"); // xóa màn hình
		showMap(map, result, 0); // hiển thị map bình thường
		printf("input x y: ");
		scanf("%d%d", &x, &y);
		if (x > 0 && x < 10 && y > 0 && y < 10) {
			// x-1, y-1 vì chỉ số mảng chỉ từ 0-8
			int point = checkPoint(map, result, x - 1, y - 1);
			if (point == -1) {
				break; // chọn mìn-> end game
			}
			else {
				score += point; // cộng điểm nhận được
			}
		}
		else { // giá trị x, y không hợp lệ
			printf("Invalid x, y. Try again!");
		}
	}
	// hiện toàn bộ mình và vị trí đã chọn:
	system("cls"); // xóa màn hình
	showMap(map, result, 1); // hiện kết quả và vị trí mìn
	printf("GAME OVER\nYOUR SCORE: %d", score);
	// giải phóng bộ nhớ cấp phát động
	for (i = 0; i < SIZE; i++)
	{
		free(map[i]);
	}
	free(map);
}

// định nghĩa chi tiết các hàm
void initMap(char** map) { // khởi tạo map ban đầu tất cả là '0'
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			map[i][j] = '0';
		}
	}
}

void setMine(char** map) { // thiết lập bãi mìn một cách ngẫu nhiên
	int i;
	srand(time(NULL));
	for (i = 0; i < SIZE; i++) {
		int j = rand() % 9;
		map[i][j] = '*';
	}
}

void initScoreMap(char** map) { // khởi tạo điểm số
	srand(time(NULL)); // sinh ngẫu nhiên các bộ số khác nhau
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (map[i][j] == '0') { // tại các vị trí khác bãi mìn
				char score = (rand() % 4) + '0'; // giả sử khởi tạo điểm từ 0-3
				map[i][j] = score;
			}
		}
	}
}

int checkPoint(char** map, char** result, int x, int y) {
	result[x][y] = '1';
	if (map[x][y] == '*') { // nếu vị trí trong map là *(mìn) thì 
		return -1; // trả về -1 => game over
	}
	else { // nếu không thì
		return map[x][y] - '0'; // trả về điểm số, xem thêm bảng mã ASCII
	}
}

void showMap(char** map, char** result, int isOver) {
	int i, j;
	// in ra vị trí cột
	printf(" "); // in ra một dấu cách ở đầu
	for (i = 0; i < SIZE; i++)
	{
		printf("%5d", i + 1);
	}
	printf("\n\n");
	// in ra map
	for (i = 0; i < SIZE; i++)
	{
		printf("%d", (i + 1));
		for (j = 0; j < SIZE; j++)
		{
			// những ô đã chọn thì hiển thị ra giá trị
			// hoặc game over thì hiện tất cả vị trí của mìn
			if (result[i][j] == '1' || (isOver == 1 && map[i][j] == '*')) {
				printf("%5c", map[i][j]);
			}
			else {
				printf("%5c", '?');
			}
		}
		printf("\n\n");
	}
}

