#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

void sumOfPrimes(int n) {
    int ok = 0;
    for (int i = 2; i <= n/2; i++) {
        int j = n - i;
        if (isPrime(i) && isPrime(j)) {
            printf("%d + %d = %d\n", i, j, n);
            ok = 1;
        }
    }
    if (!ok) printf("No combo for %d.\n", n);
}

int main() {
    int n;

    printf("Enter number: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid.\n");
        return 1;
    }

    sumOfPrimes(n);
    return 0;
}
