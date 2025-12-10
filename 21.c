#include <stdio.h>

typedef struct {
    float r, i;
} Complex;

Complex add(Complex a, Complex b) {
    Complex c;
    c.r = a.r + b.r;
    c.i = a.i + b.i;
    return c;
}

Complex mul(Complex a, Complex b) {
    Complex c;
    c.r = a.r * b.r - a.i * b.i;
    c.i = a.r * b.i + a.i * b.r;
    return c;
}

int main() {
    Complex c1, c2, sum, prod;

    printf("First complex (real imag): ");
    scanf("%f %f", &c1.r, &c1.i);

    printf("Second complex (real imag): ");
    scanf("%f %f", &c2.r, &c2.i);

    sum = add(c1, c2);
    prod = mul(c1, c2);

    printf("Sum: %.2f + %.2fi\n", sum.r, sum.i);
    printf("Product: %.2f + %.2fi\n", prod.r, prod.i);

    return 0;
}
