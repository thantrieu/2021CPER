/*
 * @author Branium Academy
 * @version 2021.10
 * @see https://braniumacademy.net
*/
#include <stdio.h>

int main() {
    float a, b;
    char op;
    puts("Nhap vao bieu thuc can tinh toan: ");
    scanf("%f %c %f", &a, &op, &b);
    float result = 0;
    int error = 0;
    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if(b == 0) {
                puts("ERROR");
                error = 1;
            } else {
                result = a / b;
            }
            break;
        default:
            puts("ERROR");
            error = 1;
            break;
    }
    if(error == 0) {
        printf("%0.2f %c %0.2f = %0.2f\n", a, op, b, result);
    }
}
