#include <stdio.h>

int main() {
    int day, month;
    puts("Nhập ngày sinh, tháng sinh cách nhau bởi dấu cách: ");
    scanf("%d%d", &day, &month);
    switch (month) {
        case 1:
            if(1 <= day && day <= 19) {
                puts("Ma Kết");
            } else if(20 <= day && day <= 31) {
                puts("Bảo Bình");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 2:
            if(1 <= day && day <= 18) {
                puts("Bảo Bình");
            } else if(19 <= day && day <= 29) {
                puts("Song Ngư");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 3:
            if(1 <= day && day <= 20) {
                puts("Song Ngư");
            } else if(21 <= day && day <= 31) {
                puts("Bạch Dương");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 4:
            if(1 <= day && day <= 20) {
                puts("Bạch Dương");
            } else if(21 <= day && day <= 30) {
                puts("Kim Ngưu");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 5:
            if(1 <= day && day <= 20) {
                puts("Kim Ngưu");
            } else if(21 <= day && day <= 31) {
                puts("Song Tử");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 6:
            if(1 <= day && day <= 21) {
                puts("Song Tử");
            } else if(22 <= day && day <= 30) {
                puts("Cự Giải");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 7:
            if(1 <= day && day <= 22) {
                puts("Cự Giải");
            } else if(23 <= day && day <= 31) {
                puts("Sư Tử");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 8:
            if(1 <= day && day <= 22) {
                puts("Sư Tử");
            } else if(23 <= day && day <= 31) {
                puts("Xử Nữ");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 9:
            if(1 <= day && day <= 22) {
                puts("Xử Nữ");
            } else if(23 <= day && day <= 30) {
                puts("Thiên Bình");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 10:
            if(1 <= day && day <= 23) {
                puts("Thiên Bình");
            } else if(24 <= day && day <= 31) {
                puts("Bọ Cạp");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 11:
            if(1 <= day && day <= 22) {
                puts("Bọ Cạp");
            } else if(23 <= day && day <= 30) {
                puts("Nhân Mã");
            } else {
                puts("INVALID DAY");
            }
            break;
        case 12:
            if(1 <= day && day <= 21) {
                puts("Nhân Mã");
            } else if(22 <= day && day <= 31) {
                puts("Ma Kết");
            } else {
                puts("INVALID DAY");
            }
            break;
        default:
            puts("INVALID MONTH");
            break;
    }
    return 0;
}
