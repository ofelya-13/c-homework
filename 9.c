#include <stdio.h>

int main() {
    int n;
    printf("n: ");
    scanf("%d", &n);

    int a[n];
    int *p = a;

    for (int i = 0; i < n; i++)
        scanf("%d", p + i);

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (*(p + i) > *(p + j)) {
                int tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }

    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");

    return 0;
}
