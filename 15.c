#include <stdio.h>
#include <string.h>

#define MAXSTR 50
#define MAXLEN 50

void sortStrings(char arr[][MAXLEN], int n, int (*cmp)(const char*, const char*)) {
    char tmp[MAXLEN];
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (cmp(arr[i], arr[j]) > 0) {
                strcpy(tmp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], tmp);
            }
}

int alphaCmp(const char *a, const char *b) {
    return strcmp(a, b);
}

int main() {
    int n;
    char arr[MAXSTR][MAXLEN];

    printf("Number of strings: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);

    sortStrings(arr, n, alphaCmp);

    printf("\nSorted strings:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    return 0;
}
