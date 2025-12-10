#include <stdio.h>

int main() {
    char s[50], r[50];
    char *p = s, *q = r;

    printf("Input: ");
    scanf("%s", s);

    while (*p) p++;  // move to end

    while (p > s) {
        p--;
        *q++ = *p;
    }

    *q = '\0';

    printf("Reversed: %s\n", r);
    return 0;
}
