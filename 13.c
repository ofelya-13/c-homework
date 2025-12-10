#include <stdio.h>

int main() {
    int r, c;
    int mat[50][50], t[50][50];

    printf("Rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Matrix elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    // Transpose
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = mat[i][j];

    printf("Transpose:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }

    return 0;
}
