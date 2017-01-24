#include <stdio.h>
int pointer(int*);
char msg(char *);
int main()
{

	int x = 5;
	int *p; //declared a pointer p pointing to an integer.
	char *s; //declared a pointer s pointing to a character.
	s = &msg; //s equals address of msg function.
	p = &x; //p contains address of x.
	printf("The Pointer is of type integer.\n");
	printf("The 5 is the value and *p points to it.\n");
	printf("The value is: %d", *p); //use x (variable) or *p (pointer) to print 5 (the value).
	printf("\nThe address of pointer is: ");
	printf("%p\n", &p); //&p or &x prints address of pointer.

	int c = 1, y = 2;
	int *ip; //declared a pointer ip pointing to integer.
	ip = &c; //ip contains address of c.
	y = *ip; //y equals to ip which contains address of c. Thus, y equals c via pointers.
	x = ip;
	*ip = 3; //x = 3 and y = 1.
	printf("The value of c is: %d, of y is: %d and of ip is: %d\n", c, y, *ip);
	printf("Actually, the x is 3 because it is equated with ip. y is 1 because it's value is changed with initial value of x.\n");
	printf("Initially, a pointer points no where, you set it to point to something.\n");
	int v = pointer(*p); //storing the value of pointer in integer variable called v.
	printf("The value of b is called out and is: %d\n", v);
	printf("Pointers are used to make local variables, global.\n");
	int n   = 4;
	int m = 5;
	double pi = 3.14159;
	double phi = 7.1245;
	int *pn = &n;
	int *pm = &m;
	double *ppi = &pi;
	double *pphi = &phi;
	pphi = (double*)pm;
	printf("The double data type pi = %g\n", *ppi); //%g is for double like %d is for int.
	printf("The double (explicitly casted) data type phi = %g\n", *pphi); //explicitly casted.
	int f = 50, k;
	int *ptr;
	ptr = &f;
	k = *ptr; //dereferencing pointer.
	printf("The dereferenced pointer k is: %d\n", k);
	printf("The pointer string is passed out is: ");
    msg(*s);
    int arr[8] = {2, 3, 4, 5, 6, 7, 8, 9};
    int g = arr[0];
    int *pg = &arr[0];
    printf("\nThe pointer to 1th element of array is: %d\n", (*pg+1)); //Pointer arithmetic.
    int r = 5;
    int *pts = &r;
    *pts = 6; //Pointer updates the value of r.
    printf("The updated value of r is: %d", r);
    return 0;

}
int pointer(int *p) //a function declared with a pointer passed as an argument.
{
	int b = 10;
	p = &b;
	return *p; //Return pointer p pointing to address of 5.
}
char msg(char *s)
{
    char msg[] = "Aren't pointer's fun?";
    s = msg;
    printf("%s", s);
}
