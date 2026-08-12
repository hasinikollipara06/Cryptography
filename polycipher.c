#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[200], key[100];
    char plain[200], keyword[100], cipher[200];

    int i, j = 0, k;
    int textLen = 0, keyLen = 0;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    /* Prepare plaintext */

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            plain[textLen++] = toupper((unsigned char)text[i]);
        }
        else if (text[i] != ' ')
        {
            printf("%c cannot be encrypted and will be ignored.\n",
                   text[i]);
        }
    }

    plain[textLen] = '\0';

    /* Prepare keyword */

    for (i = 0; key[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)key[i]))
        {
            keyword[keyLen++] = toupper((unsigned char)key[i]);
        }
        else if (key[i] != ' ')
        {
            printf("%c in keyword cannot be used and will be ignored.\n",
                   key[i]);
        }
    }

    keyword[keyLen] = '\0';

    if (textLen == 0)
    {
        printf("No alphabetic characters found in plaintext.\n");
        return 0;
    }

    if (keyLen == 0)
    {
        printf("No alphabetic characters found in keyword.\n");
        return 0;
    }

    /* Encryption */

    for (i = 0; i < textLen; i++)
    {
        k = (plain[i] - 'A' +
             keyword[j % keyLen] - 'A') % 26;

        cipher[i] = k + 'A';
        j++;
    }

    cipher[textLen] = '\0';

    printf("\nPrepared Text: %s\n", plain);
    printf("Key: %s\n", keyword);
    printf("Ciphertext: %s\n", cipher);

    return 0;
}