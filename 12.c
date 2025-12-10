#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char names[50][50];

    printf("Number of names: ");
    scanf("%d", &n);

    printf("Enter names:\n");
    for (int i = 0; i < n; i++)
        scanf("%s", names[i]);

    printf("Duplicates:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                printf("%s\n", names[i]);
                break;
            }
        }
    }

    return 0;
}
