#include<stdio.h>
#include<string.h>

#include<ctype.h>
int main()
{
    char message[100];
    int key;
    void encrypt(char message[], int key);
    void decrypt(char message[], int key);

    printf("Please Enter the Message to be Encrypted: \n");
    gets(message);
    printf("Enter the key: \n");
    scanf("%d", &key);
    printf("The encrypted message is: ");
    encrypt(message, key);
    printf("\n");
    printf("The decrypted message is: ");
    decrypt(message, key);
    return 0;
}

void encrypt (char message[], int key)
{
  int i;
    for (i = 0; i < strlen(message); i++)
        {
        if (message[i] >= 'a' && message[i] <= 'z'){
            message[i] = message[i] + key;
            if (message[i] > 'z')
            {
                message[i] = message[i] - 26;
            }
            }
        else if (message[i] >= 'A' && message[i] <= 'Z'){
                message[i] = message[i] + key;
                    if (message[i] > 'Z')
                {
                    message[i] = message[i] - 26;
                }
                }
        }
        printf("%s", message);
}
void decrypt (char message[], int key)
{
    int i;
    for (i = 0; i < strlen(message); i++)
        {
        if (message[i] >= 'a' && message[i] <= 'z'){
            message[i] = message[i] - key;
            if (message[i] < 'a')
            {
                message[i] = message[i] + 26;
            }
            }
        else if (message[i] >= 'A' && message[i] <= 'Z'){
                message[i] = message[i] - key;
                    if (message[i] < 'A')
                {
                    message[i] = message[i] + 26;
                }
                }
        }
        printf("%s", message);
}

