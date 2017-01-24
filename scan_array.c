#include <stdio.h>

int max_array(char a[], int elements)

{
	int index;
	for (index = 0; index < elements; index++)
	{
		if (a[index] == '-'){
			a[index] = '_';
		}
	}

}

int main(void)
{	
	int index;
	char a[6] = {'A', 'B', 'c', 'd', 'e', '-'};
	printf("\nArray\n");
	max_array(a, 6);
	for (index = 0; index < 6; index++){
	printf("\t%d", a[index]);
}

	printf("\n");
	return 0;
}



