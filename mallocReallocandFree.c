#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char* str;
    str = (char*) malloc( 3 * sizeof(char));
    strcpy(str, "hi");
    printf("The allocated string is: %s\n", str);
    str = (char*) realloc( str , 6 * sizeof(char) );
    strcpy(str, "hello");
    printf("The reallocated string is: %s\n", str);
    str = (char*) realloc(str, 13 *sizeof(char));
    strcpy(str, "Kamran Janjua");
    printf("The re-reallocated string is: %s\n", str);
    free(str);
    printf("The freed string is: %s\n", str); //prints garbage.
    int num, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    ptr = (int*) malloc(num * sizeof(int));  //memory allocated using malloc
    if(ptr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements of array: ");
    for(i = 0; i < num; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d", sum);
    free(ptr);
    return 0;
}
