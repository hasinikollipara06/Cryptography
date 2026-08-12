#include <stdio.h>
#include <string.h>

void railFenceEncrypt(const char *text, int depth, char *result)
{
    int len = strlen(text);
    char fence[20][200];
    int rowLen[20] = {0};

    int row = 0, dir = 1;

    for (int i = 0; i < len; i++)
    {
        fence[row][rowLen[row]++] = text[i];

        if (row == 0)
            dir = 1;
        else if (row == depth - 1)
            dir = -1;

        row += dir;
    }

    int idx = 0;

    for (int r = 0; r < depth; r++)
    {
        for (int c = 0; c < rowLen[r]; c++)
            result[idx++] = fence[r][c];
    }

    result[idx] = '\0';
}

void railFenceDecrypt(const char *cipher, int depth, char *result)
{
    int len = strlen(cipher);
    char fence[20][200];
    int rowLen[20] = {0};

    int row = 0, dir = 1;

    for (int i = 0; i < len; i++)
    {
        rowLen[row]++;

        if (row == 0)
            dir = 1;
        else if (row == depth - 1)
            dir = -1;

        row += dir;
    }

    int pos = 0;

    for (int r = 0; r < depth; r++)
    {
        for (int c = 0; c < rowLen[r]; c++)
            fence[r][c] = cipher[pos++];
    }

    int rowIdx[20] = {0};

    row = 0;
    dir = 1;

    for (int i = 0; i < len; i++)
    {
        result[i] = fence[row][rowIdx[row]++];

        if (row == 0)
            dir = 1;
        else if (row == depth - 1)
            dir = -1;

        row += dir;
    }

    result[len] = '\0';
}

int main()
{
    char text[200], cipher[200], decrypted[200];
    int depth;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    printf("Enter depth: ");
    scanf("%d", &depth);

    if (depth < 2 || depth > 20)
    {
        printf("Invalid depth!\n");
        return 1;
    }

    railFenceEncrypt(text, depth, cipher);
    printf("Ciphertext: %s\n", cipher);

    railFenceDecrypt(cipher, depth, decrypted);
    printf("Decrypted : %s\n", decrypted);

    return 0;
}