#include "stdio.h"
#include "stdlib.h"

int main()
{
    char c;
    int isLowercaseVowel, isUppercaseVowel;

    printf("Enter an alphabet:\n");
    scanf("%c", &c);

    isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (isLowercaseVowel || isUppercaseVowel)
        printf("%c is a vowel.\n", c);

    else
        printf("%c is a consonant.\n", c);
    return 0;
}
