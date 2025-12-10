#include <stdio.h>

void sum_avg(int *p, int n, int *sum, float *avg) {
    *sum = 0;
    for (int i = 0; i < n; i++)
        *sum += p[i];
    *avg = (float)(*sum) / n;
}

int main() {
    int n, sum;
    float avg;

    printf("Number of elements: ");
    scanf("%d", &n);

    int arr[n], *p = arr;

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", p + i);

    sum_avg(p, n, &sum, &avg);

    printf("Sum = %d\nAverage = %.2f\n", sum, avg);

    return 0;
}
