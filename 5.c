#include <stdio.h>

int main() {
    char line[256];
    int a, b;
    char op;

    printf("Enter expressions:\n");

    while (fgets(line, sizeof(line), stdin)) {

        if (sscanf(line, "%d %c %d", &a, &op, &b) != 3) {
            printf("Error\n");
            continue;
        }

        if ((op == '/' || op == '%') && b == 0) {
            printf("Error: zero division\n");
            continue;
        }

        switch (op) {
            case '+': printf("= %d\n", a + b); break;
            case '-': printf("= %d\n", a - b); break;
            case '*': printf("= %d\n", a * b); break;
            case '/': printf("= %d\n", a / b); break;
            case '%': printf("= %d\n", a % b); break;
            default:  printf("Error: bad op\n");
        }
    }

    return 0;
}
