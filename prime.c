#include <stdio.h>

int main()
{
    long long n, i;

    printf("Enter a number: ");
    scanf("%lld", &n);

    if (n < 2)
    {
        printf("%lld is not a prime number.\n", n);
        return 0;
    }

    if (n == 2)
    {
        printf("%lld is a prime number .\n", n);
        return 0;
    }

    if (n % 2 == 0)
    {
        printf("%lld is not a prime number.\n", n);
        return 0;
    }

    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            printf("%lld is not a prime number.\n", n);
            return 0;
        }
    } 

    printf("%lld is a prime number.\n", n);

    return 0;
}