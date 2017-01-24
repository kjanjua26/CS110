#include<stdio.h>
#include <time.h>

int main()
{
    int fahr, celsius;
    int lower, upper, step;
    int a, b;
    do {
        printf("Please input the integer a: \n");
        scanf("%d", &a);

        srand(time(NULL));
        int r = rand() % 6; //returns a value from 0 to 5.
        b = a + r;
        printf("The sum of your input and random number generated is: %d\n", b);

    } while ( b <= 100);

        lower = 0;
        upper = 300;
        step = 30;
        fahr = lower;
        while (fahr <= upper){
        celsius = 5 * (fahr-32)/9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }

void foo()
{
	int a;
	int b;
	printf("Please enter a value for a: ");
	scanf("%d", &a);

	printf("Please enter a value for b: ");
	scanf("%d", &b);

	printf("The value you entered for a and b are: %d, %d", a, b);

}

    return 0;
}
