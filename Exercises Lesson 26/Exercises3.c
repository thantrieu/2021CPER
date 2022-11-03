// Cho mảng nguyên gồm n phần tử. Viết chương trình thực hiện các chức năng:
// nhập vào n phần tử của mảng
// hiển thị mảng ra màn hình
// xác định độ dài đường chạy tăng dài nhất
// hiển thị tất cả các đường chạy dài nhất ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập mảng và x
void getElements(int a[], int n);
// hàm hiển thị mảng
void showElements(int a[], int from, int to);
// hàm tìm độ dài đường chạy tăng dài nhất
int maxLength(int a[], int n);
// hàm liệt kê kết quả
int showResult(int a[], int n);

int main() {
	int n;
	int arr[100];
	puts("Nhap so phan tu mang: ");
	scanf("%d", &n);
	if (n > 0) {
		// nhập các phần tử mảng
		puts("Nhap cac phan tu mang: ");
		getElements(arr, n);
		// hiện mảng
		puts("Cac phan tu trong mang:");
		showElements(arr, 0, n);
		// liệt kê kết quả
		int max = showResult(arr, n);
		printf("So duong chay max: %d\n", max);
	}
	else {
		puts("Nhap n > 0");
	}
	return 0;
}

int maxLength(int a[], int n) {
	int count = 1; // biến đếm số phần tử của đường chạy
	int max = 1; // độ dài lớn nhất mặc định là 1
	int i;
	for (i = 0; i < n; i++) {
		// nếu phần tử sau nhỏ hơn phần tử trước
		if (i + 1 < n && a[i] <= a[i + 1]) {
			count++;
		}
		else { // phần tử kế tiếp thuộc đường chạy khác
			if (count > max) {
				max = count;
			}
			count = 1; // reset lại biến count
		}
	}
	return max; // trả về độ dài max tìm đc
}

int showResult(int a[], int n) {
	int max = maxLength(a, n);
	printf("Do dai max: %d\n", max);
	int count = 0; // biến đếm số đường chạy dài nhất
	int i;
	int startIndex = 0;
	int curLen = 1; // độ dài mặc định của một đường chạy
	puts("Danh sach cac duong chay dai nhat: ");
	for (i = 0; i < n; i++) {
		if (i + 1 < n && a[i] <= a[i + 1]) {
			curLen++;
		}
		else { // phần tử kế tiếp thuộc đường chạy khác
			if (curLen == max) { // nếu là đường chạy max
				count++;// tăng số lượng đường chạy max lên
				printf("D%d: ", count);
				showElements(a, startIndex, startIndex + max); // hiện đường chạy
			}
			curLen = 1; // reset lại biến giám sát độ dài đường chạy
			startIndex = i + 1;// đánh dấu vị trí bắt đầu đ.chạy mới
		}
	}
	return count;
}

void showElements(int a[], int from, int to) {
	int i;
	for (i = from; i < to; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void getElements(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}