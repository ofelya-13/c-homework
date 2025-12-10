#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 200

int main(int argc, char *argv[]) {
    int n = 10;
    if (argc == 2 && argv[1][0] == '-')
        n = atoi(argv[1] + 1);

    char lines[MAXLINES][MAXLEN];
    int count = 0;

    printf("Enter text:\n");
    while (count < MAXLINES && fgets(lines[count], MAXLEN, stdin))
        count++;

    int start = count - n;
    if (start < 0) start = 0;

    printf("\nLast %d lines:\n", n);
    for (int i = start; i < count; i++)
        printf("%s", lines[i]);

    return 0;
}
