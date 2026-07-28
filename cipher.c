#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int key, choice, i;

    printf("1. Encryption\n");
    printf("2. Decryption\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the key: ");
    scanf("%d", &key);

    key = key % 26;

    printf("Enter the text: ");
    scanf(" %[^\n]", text);

    if (choice == 1)
    {
        for (i = 0; text[i] != '\0'; i++)
        {
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] = ((text[i] - 'A' + key) % 26) + 'A';
            }
            else if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] = ((text[i] - 'a' + key) % 26) + 'a';
            }
        }

        printf("\nEncrypted Text: %s\n", text);
    }
    else if (choice == 2)
    {
        for (i = 0; text[i] != '\0'; i++)
        {
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] = ((text[i] - 'A' - key + 26) % 26) + 'A';
            }
            else if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] = ((text[i] - 'a' - key + 26) % 26) + 'a';
            }
        }

        printf("\nDecrypted Text: %s\n", text);
    }
    else
    {
        printf("\nInvalid Choice\n");
    }

    return 0;
}