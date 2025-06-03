#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float x1, x2;
    float d, realPart, imaginaryPart;

    printf("Enter the coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a != 0) {
        d= b * b - 4 * a * c;

        if (d > 0) {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            printf("\n%f", x1);
            printf("\n%f", x2);
        } else if (d == 0) {
            x1 = -b / (2 * a);
            printf("\n%f", x1);
        } else {
            realPart = -b / (2 * a);
            imaginaryPart = sqrt(-d) / (2 * a);
            printf("\n%f + %fi", realPart, imaginaryPart);
            printf("\n%f - %fi", realPart, imaginaryPart);
        }
    } else {
        printf("Invalid input");
    }

    return 0;
}
