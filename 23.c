#include <stdio.h>
#include <string.h>

#define MAX 200

int main() {
    char f1name[50], f2name[50];
    char line1[MAX], line2[MAX];
    FILE *f1, *f2;
    int ln = 1;

    printf("First file: "); scanf("%s", f1name);
    printf("Second file: "); scanf("%s", f2name);

    f1 = fopen(f1name, "r");
    f2 = fopen(f2name, "r");

    if (!f1 || !f2) { printf("Error opening files.\n"); return 1; }

    while (fgets(line1, MAX, f1) && fgets(line2, MAX, f2)) {
        if (strcmp(line1, line2) != 0) {
            printf("Diff at line %d:\nFile1: %sFile2: %s", ln, line1, line2);
            fclose(f1); fclose(f2);
            return 0;
        }
        ln++;
    }

    if (fgets(line1, MAX, f1) || fgets(line2, MAX, f2))
        printf("Files differ at line %d (extra lines in one file).\n", ln);

    fclose(f1); fclose(f2);
    return 0;
}
