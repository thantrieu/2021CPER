#include <stdio.h>

int main() {
    char c = getchar();
    switch (c) {
        case 'a':
        case 'A':
            puts("Giỏi");
            break;
        case 'b':
        case 'B':
            puts("Khá");
            break;
        case 'c':
        case 'C':
            puts("Trung bình");
            break;
        case 'd':
        case 'D':
            puts("Yếu");
            break;
        case 'f':
        case 'F':
            puts("Liệt");
            break;
        default:
            puts("INVALID");
            break;
    }
    return 0;
}
