#include "stdio.h"
#include "conio.h"
int main()
{
    FILE *fp; //file type pointer declared.
    char ch;
    fp = fopen("text.txt", "w"); //file name text and mode write.
    printf("Input line and press End Of File(EOF): \n");
    while ((ch = getchar()) != EOF)
    {
       putc(ch, fp); //to write the character in text.txt
    }
    fclose(fp); //closes the file.

    printf("Output: \n");
    fp = fopen("text.txt", "r"); //opens the file text and reads it.

    while ((ch = getc(fp)) != EOF) //continues when the EOF mark doesn't appear.
    {
        printf("%c\n", ch);
    }

    fclose(fp);

    getch();

}
