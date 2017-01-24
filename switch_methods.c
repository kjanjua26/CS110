#include <stdio.h>
int main()
{
    int cho;
    printf("Please enter a number from 1 to 3: ");
    scanf("%d", &cho);

    switch (cho){
    case 1:
        printf("It is one!\n");
        break;
    case 2:
        printf("It is two!\n");
        break;
    case 3:
        printf("It is three!\n");
        break;
    default:
        printf("Invalid!\n");

    int a = 1, b = 2 ;
    printf ( "a : %d, b : %d\n", a, b ) ;
    swap ( a , b ) ;
    printf ( "a : %d, b : %d\n", a, b ) ;
    }

int swap ( int i, int j )
{
    int t = i;
    i = j;
    j = t;

}
}

