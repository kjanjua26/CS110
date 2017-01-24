#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int a, b;
    char message[100];
    char s[100] = "Hello World";
    sprintf(message, "Message: %s", s); //s is stored in array of characters, message.
    puts(message);

    char src[100] = "Hey People!";
    char dest[100];
    memcpy(dest, src, sizeof(src)/sizeof(char)); //copies strlen till 3 of src to dest.
    printf("The copied string from src is: %s\n", dest);
    //strlen copies the null character as well while sizeof doesn't.
    char src2[100] = "Overlapping";
    memmove(dest, src2, sizeof(src2)/sizeof(char));
    //memmove works even if the areas overlap.
    printf("The overlapped string is: %s\n", dest);
    char * re = strchr(src2, 'O'); //If O is found then it returns pointer to str2 else to null char.
    printf("%s", re);
    if (strcmp(src2,dest)==0){printf("\nSame.");}
    if(strcmp(src,dest)!=0){printf("\nNo.Not Same.");}
    do{
    printf("\nEnter one number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    int c = func(a,b);
    printf("The product is: %d", c);
    } while(a != 0 || b != 0);
    struct movie{
    char actor[50];
    int movies;
    int salary;
    int ratio }ac1 = {"Shaan", 5, 5*100, ((5*100)/5)};

    printf("\nThe actor name is: %s", ac1.actor);
    printf("\nThe ratio is: %d", ac1.ratio);
    int chh = ac1.salary;
    printf("\nSalary: %d", chh);
    return 0;
}
int func (int a, int b)
{
    int sum = 0;
    sum = (a*b);
    return sum;
}
