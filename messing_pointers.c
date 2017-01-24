#include "stdio.h"
#include "ctype.h"

void cubeByReference(int *nptr);
void convertToUppercase (char *sptr);
int main(void)

    {
        char string[] = "characters and $32.98";
        int number = 5;
        int tuna = 10;
        int *tptr;
        tptr = &tuna;
        printf("The pointer tuna is: %d\n", *tptr);
        printf("The address of tuna is: %p\n", &tuna);
        printf("The original value of number is: %d\n", number);
        printf("The string before conversion is: %s\n", string);
        cubeByReference(&number);
        convertToUppercase(string);
        printf("The string after conversion is: %s\n", string);
        printf("The new value of number is %d\n", number);
        int y = 5;
        int *yptr;
        yptr = &y;
        printf("The pointer is: %d\n", *yptr);
        return 0;
    }

    void cubeByReference(int *nptr)

    {
        *nptr = *nptr * *nptr * *nptr;

    }

    void convertToUppercase(char *sptr){
    while (*sptr != '\0'){
        if (islower(*sptr)){
            *sptr = toupper(*sptr);
        }
        ++sptr;
    }

}


