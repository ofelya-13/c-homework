#include <stdio.h>

int main() {
    int arr[50], n;

    printf("Number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", arr + i);
    }

    printf("You entered:\n");
    for (int i = 0; i < n; i++)
        printf("Element %d: %d\n", i, *(arr + i));

    return 0;
}
