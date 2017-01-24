#include "stdio.h"
#include "ctype.h"
int main()
{
    char ch;
    printf("\nEnter the character: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z')
        printf("Character is Upper Case\n");
    if (ch >= 'a' && ch <= 'z')
        printf("Character is Lower Case\n");

    return 0;
}
