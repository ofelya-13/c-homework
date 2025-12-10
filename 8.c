#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void perm(char *w, int l, int r) {
    if (l == r) {
        printf("%s  ", w);
    } else {
        for (int i = l; i <= r; i++) {
            swap(&w[l], &w[i]);
            perm(w, l + 1, r);
            swap(&w[l], &w[i]);
        }
    }
}

int main() {
    char w[50];
    printf("Word: ");
    scanf("%49s", w);

    perm(w, 0, strlen(w) - 1);
    printf("\n");
    return 0;
}
