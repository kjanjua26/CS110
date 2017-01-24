#include "stdio.h"
#include "string.h"

    struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;

    };

/* Function Declaration */
void printBook (struct Books *book);

int main()

{
    struct Books Book1; /*Declare Book1 of type Book */
    struct Books Book2; /*Declare Book2 of type Book */

    //Book 1 specification
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Kamran Janjua");
    strcpy(Book1.subject, "C Tutorials");
    Book1.book_id = 182599;

    //Book 2 specification
    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Peter Jay");
    strcpy(Book2.subject, "Billing Tutorial");
    Book1.book_id = 182588;

    //print Book1 info by passing the address of Book1
    printBook(&Book1);
    //print Book1 info by passing the address of Book2
    printBook(&Book2);

    return 0;
}

void printBook(struct Books *book)

{

printf("Book Title: %s\n", book-> title);
printf("Book author: %s\n", book-> author);
printf("Book subject: %s\n", book-> subject);
printf("Book book_id: %d\n", book-> book_id);

}
