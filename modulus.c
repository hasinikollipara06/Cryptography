#include <stdio.h>

int main()
{
    float divisor, dividend, remainder, quotient;

    printf("Enter the dividend: ");
    scanf("%f", &dividend);

    printf("Enter the divisor: ");
    scanf("%f", &divisor);

    if (divisor <= 0)

    {
        printf("Division not allowed.\n");
    }
    else
    {
        quotient = dividend / divisor;
        remainder = dividend - ((int)quotient * divisor);

        printf("Modulus of %f and %f is: %f\n", dividend, divisor, remainder);
    }

    return 0;
}