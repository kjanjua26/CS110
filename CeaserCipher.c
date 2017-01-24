#include<stdio.h>
#include<string.h>

int main()
{
    unsigned char message[100]; //To get rid of signed characters.
    int key, choice;
    void encrypt(unsigned char message[], int key); //Encrypt function prototype.
    void decrypt(unsigned char message[], int key); //Decrypt function prototype.

    printf("|------------------------------------|\n");
    printf("|\tWelcome to Caesar Cipher     |\n");
    printf("|                                    |\n");
    printf("|------------------------------------|\n");
    printf("\n");
    printf("Please Enter the Message to be Encrypted: \n"); //Asking the user to enter the message to encrypt.
    gets(message);
    printf("Enter the key: "); //Asking the user for the key to encrypt with.
    scanf("%d", &key);
    printf("\n\n");
    printf("The encrypted message is: ");
    encrypt(message, key); //Calling the function encrypt.
    printf("\n");
    printf("The decrypted message is: ");
    decrypt(message, key); //Calling the function decrypt.
    printf("\n\n");
    return 0;
}

void encrypt (unsigned char message[], int key)
{
  int i, c = 0;
    for (i = 0; i < strlen(message); i++) //for loop to continue till i is less than length of message entered.
        {
        if (message[i] >= 'a' && message[i] <= 'z'){ //Since, we are leaving special characters, so it is between a and z.
            message[i] = message[i] + key; //Add key in the value to move to that character.
            if (message[i] > 'z')
            {
                message[i] = message[i] - 26; //If the value is greater than z, then subtract 26 from it to get exact value.
            }
        }
           else if (message[i] >= 'A' && message[i] <= 'Z'){ //For upper case letters.
                message[i] = message[i] + key;
                    if ((message[i] > 'Z') && ( message[i] <= 'Z' + 25 ))
                {
                    message[i] = message[i] - 26; //For upper case letters.
                }
                }
        }
        printf("%s", message); //Prints out the message.
}
void decrypt (unsigned char message[], int key)
{
    int i;
    for (i = 0; i < strlen(message); i++) //for loop to continue till i is less than length of message entered.
        {
        if (message[i] >= 'a' && message[i] <= 'z'){ //Since, we are leaving special characters, so it is between a and z.
            message[i] = message[i] - key; //Subtract key from the value to move back to the character.
            if ((message[i] < 'a') && ( message[i] >= 72 ))
            {
                message[i] = message[i] + 26; //If the value is less than that of a, then add 26 to get to exact value.
            }
            }
        else if (message[i] >= 'A' && message[i] <= 'Z'){ //For upper case letters.
                message[i] = message[i] - key;
                    if ((message[i] < 'A') && ( message[i] >= 40 ))
                {
                    message[i] = message[i] + 26; //For upper case letters.
                }
                }
        }
        printf("%s", message); //Prints out the message.
}
