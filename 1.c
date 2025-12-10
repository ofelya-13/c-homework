#include <stdio.h>

int escape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i]) {
        if (t[i] == '\n') { s[j++]='\\'; s[j++]='n'; }
        else if (t[i] == '\t') { s[j++]='\\'; s[j++]='t'; }
        else if (t[i] == '\\') { s[j++]='\\'; s[j++]='\\'; }
        else s[j++] = t[i];
        i++;
    }
    s[j] = '\0';
    return 0;
}

int unescape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i]) {
        if (t[i]=='\\') {
            if (t[i+1]=='n') { s[j++]='\n'; i+=2; continue; }
            if (t[i+1]=='t') { s[j++]='\t'; i+=2; continue; }
            if (t[i+1]=='\\') { s[j++]='\\'; i+=2; continue; }
        }
        s[j++] = t[i++];
    }
    s[j] = '\0';
    return 0;
}

int main() {
    char text[150], esc[150], unesc[150];
    int c, k = 0;

    while ((c = getchar()) != EOF && k < 149)
        text[k++] = c;
    text[k] = '\0';

    escape(esc, text);
    printf("Escaped:\n%s\n", esc);

    unescape(unesc, esc);
    printf("Unescaped:\n%s\n", unesc);

    return 0;
}
