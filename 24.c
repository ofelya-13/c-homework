#include <stdio.h>
#include <string.h>

#define MAX 200

int main() {
    char fname[50], word[50], line[MAX];
    FILE *f;

    printf("File name: "); scanf("%s", fname);
    printf("Word to search: "); scanf("%s", word);

    f = fopen(fname, "r");
    if (!f) { printf("Cannot open file.\n"); return 1; }

    printf("\nLines with '%s':\n", word);
    while (fgets(line, MAX, f)) {
        if (strstr(line, word))
            printf("%s", line);
    }

    fclose(f);
    return 0;
}
