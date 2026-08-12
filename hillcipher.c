#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

int main()
{
    char str[500], temp[500], result[500];
    int key[MAX][MAX];
    int n;
    int i, j, k;
    int len = 0, pos = 0;
    int block[MAX], output[MAX];

    printf("Enter matrix size: ");
    scanf("%d", &n);

    if (n < 2 || n > MAX)
    {
        printf("Invalid matrix size.\n");
        return 0;
    }

    printf("Enter the %d x %d matrix:\n", n, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &key[i][j]);
        }
    }

    getchar();

    printf("Enter the string to be encrypted:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    /* Remove spaces and report numbers/special characters */

    for (i = 0; str[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)str[i]))
        {
            temp[len++] = toupper((unsigned char)str[i]);
        }
        else if (str[i] != ' ')
        {
            printf("%c cannot be encrypted and will be ignored.\n",
                   str[i]);
        }
    }

    temp[len] = '\0';

    if (len == 0)
    {
        printf("No alphabetic characters found.\n");
        return 0;
    }

    /* Add X padding */

    while (len % n != 0)
    {
        temp[len++] = 'X';
    }

    temp[len] = '\0';

    /* Hill Cipher Encryption */

    for (i = 0; i < len; i += n)
    {
        for (j = 0; j < n; j++)
        {
            block[j] = temp[i + j] - 'A';
        }

        for (j = 0; j < n; j++)
        {
            output[j] = 0;

            for (k = 0; k < n; k++)
            {
                output[j] += key[j][k] * block[k];
            }

            output[j] = output[j] % 26;
        }

        for (j = 0; j < n; j++)
        {
            result[pos++] = output[j] + 'A';
        }
    }

    result[pos] = '\0';

    printf("\nPrepared Text: %s\n", temp);
    printf("Encrypted String: %s\n", result);

    return 0;
}