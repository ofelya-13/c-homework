#include <stdio.h>

typedef struct {
    int h, m, s;
} Time;

Time addTime(Time t1, Time t2) {
    Time t;
    t.s = t1.s + t2.s;
    t.m = t1.m + t2.m + t.s / 60;
    t.s %= 60;
    t.h = t1.h + t2.h + t.m / 60;
    t.m %= 60;
    return t;
}

int main() {
    Time t1, t2, t3;

    printf("First time (hh mm ss): ");
    scanf("%d %d %d", &t1.h, &t1.m, &t1.s);

    printf("Second time (hh mm ss): ");
    scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

    t3 = addTime(t1, t2);

    printf("Sum: %02d:%02d:%02d\n", t3.h, t3.m, t3.s);
    return 0;
}
