#include <stdio.h>

void pyramid(int n) {
    for (int i = 1; i <= n; i++) {

        for (int s = 0; s < n - i; s++)
            printf(" ");

        for (int k = 0; k < i; k++)
            printf("* ");

        printf("\n");
    }
}

int main() {
    int n;
    printf("Rows: ");
    scanf("%d", &n);
    pyramid(n);
    return 0;
}
