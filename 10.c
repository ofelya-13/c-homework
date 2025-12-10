#include <stdio.h>

int main() {
    char a[26];
    char *p = a;

    for (int i = 0; i < 26; i++)
        p[i] = 'A' + i;

    p = a;

    for (int i = 0; i < 26; i++)
        printf("%c ", *(p + i));

    printf("\n");
    return 0;
}
