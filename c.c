#include <stdio.h>
#include <conio.h>
#include <ctype.h>
void main()
    {
    int i, c, key;
    char str[100];

    printf("Enter the Text Message : ");
    gets(str);
    printf("Enter the key: \n");
    printf("%d", &key);

    for (i = 0; i < strlen(str); i++)
        {
        switch (str[i])
            {
            case 'x':
                str[i] = 'a';
                continue;
            case 'y':
                str[i] = 'b';
                continue;
            case 'z':
                str[i] = 'c';
                continue;
            case 'X':
                str[i] = 'A';
                continue;
            case 'Y':
                str[i] = 'B';
                continue;
            case 'Z':
                str[i] = 'C';
                continue;
            }

        if (str[i] >= 'a' && str[i] < 'x')
            str[i] = str[i] + key;
        else if (str[i] >= 'A' && str[i] < 'X')
            str[i] = str[i] + key;
        }

    printf("Message After Encryption : \n");
    puts(str);
    for (i = 0; i < strlen(str); i++)
        {

        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - key;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - key;

        }
    printf("Message After Decryption : \n");
    puts(str);
    }
