#include <stdio.h>

void doubleVal(int *x) {
    *x = *x * 2;
}

int main() {
    int n;
    printf("Number: ");
    scanf("%d", &n);

    doubleVal(&n);

    printf("Doubled: %d\n", n);
    return 0;
}
