#include <stdio.h>

void copy_arr(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);

    int a[n], b[n], *p = a, *q = b;

    printf("Array A elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", p + i);

    copy_arr(p, q, n);

    printf("Array B after copying:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    printf("\n");

    return 0;
}
