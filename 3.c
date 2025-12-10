#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i = 0, j = strlen(s) - 1;
    char t;
    while (i < j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++; j--;
    }
}

void itob(int n, char s[], int b) {
    if (b < 2 || b > 36) { s[0] = 0; return; }

    unsigned int x = (n < 0) ? -n : n;
    int i = 0;

    while (x > 0) {
        int d = x % b;
        if (d < 10) s[i++] = '0' + d;
        else s[i++] = 'A' + (d - 10);
        x /= b;
    }

    if (n == 0) s[i++] = '0';
    if (n < 0 && b == 10) s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main() {
    int n, base;
    char s[100];

    printf("Enter integer: ");
    scanf("%d", &n);

    printf("Enter base 2-36: ");
    scanf("%d", &base);

    itob(n, s, base);
    printf("Result: %s\n", s);

    return 0;
}
