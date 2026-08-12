#include <stdio.h>
#include <string.h>
#include <ctype.h>

void createMatrix(char key[], char matrix[5][5])
{
    int used[26] = {0};
    int r = 0, c = 0;
    char ch;

    used['J' - 'A'] = 1;

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)key[i]))
        {
            ch = toupper((unsigned char)key[i]);

            if (ch == 'J')
                ch = 'I';

            if (!used[ch - 'A'])
            {
                used[ch - 'A'] = 1;
                matrix[r][c] = ch;
                c++;

                if (c == 5)
                {
                    c = 0;
                    r++;
                }
            }
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++)
    {
        if (ch == 'J')
            continue;

        if (!used[ch - 'A'])
        {
            used[ch - 'A'] = 1;
            matrix[r][c] = ch;
            c++;

            if (c == 5)
            {
                c = 0;
                r++;
            }
        }
    }
}

void findPosition(char matrix[5][5], char ch, int *row, int *col)
{
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main()
{
    char key[100];
    char str[200];
    char plain[200];
    char prepared[400];
    char result[400];
    char matrix[5][5];

    int i;
    int n = 0;
    int k = 0;
    int r1, c1, r2, c2;

    printf("Enter the key:\n");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    printf("Enter the string to be encrypted:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    /* Check and clean input */

    for (i = 0; str[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)str[i]))
        {
            plain[n] = toupper((unsigned char)str[i]);

            if (plain[n] == 'J')
                plain[n] = 'I';

            n++;
        }
        else if (str[i] != ' ')
        {
            printf("%c cannot be encrypted and will be ignored.\n",
                   str[i]);
        }
    }

    plain[n] = '\0';

    if (n == 0)
    {
        printf("No alphabetic characters found.\n");
        return 0;
    }

    /* Create pairs */

    i = 0;

    while (i < n)
    {
        prepared[k++] = plain[i];

        if (i + 1 < n)
        {
            if (plain[i] == plain[i + 1])
            {
                prepared[k++] = 'X';
                i++;
            }
            else
            {
                prepared[k++] = plain[i + 1];
                i += 2;
            }
        }
        else
        {
            prepared[k++] = 'X';
            i++;
        }
    }

    prepared[k] = '\0';

    /* Create Playfair matrix */

    createMatrix(key, matrix);

    printf("\nPlayfair Matrix:\n");

    for (i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", matrix[i][j]);
        }

        printf("\n");
    }

    /* Encrypt pairs */

    for (i = 0; i < k; i += 2)
    {
        findPosition(matrix, prepared[i], &r1, &c1);
        findPosition(matrix, prepared[i + 1], &r2, &c2);

        if (r1 == r2)
        {
            result[i] =
                matrix[r1][(c1 + 1) % 5];

            result[i + 1] =
                matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            result[i] =
                matrix[(r1 + 1) % 5][c1];

            result[i + 1] =
                matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            result[i] =
                matrix[r1][c2];

            result[i + 1] =
                matrix[r2][c1];
        }
    }

    result[k] = '\0';

    printf("\nPrepared Text: %s\n", prepared);
    printf("Encrypted String: %s\n", result);

    return 0;
}