#include <stdio.h>
#include <ctype.h>

void expand(char in[], char out[]) {
    int i = 0, j = 0;

    while (in[i] != '\0') {
        if (in[i] == '-' && i > 0 && in[i+1] != '\0') {
            char a = in[i-1];
            char b = in[i+1];

            if ((isdigit(a) && isdigit(b) && a < b) ||
                (islower(a) && islower(b) && a < b) ||
                (isupper(a) && isupper(b) && a < b)) {

                for (char c = a + 1; c <= b; c++)
                    out[j++] = c;

                i++; 
            } else {
                out[j++] = '-';
            }
        } else {
            out[j++] = in[i];
        }
        i++;
    }

    out[j] = '\0';
}

int main() {
    char s1[100], s2[300];

    printf("Enter shorthand: ");
    fgets(s1, 100, stdin);

    expand(s1, s2);

    printf("Expanded: %s\n", s2);
    return 0;
}
