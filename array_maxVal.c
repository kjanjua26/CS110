#include <stdio.h>
int max_array(int a[], int elements);

int main(void)
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 50, 9, 10};
	int max;
	printf("\nArray\n");
	max = max_array(a, 10);
	printf("\nThe max value is: %d\n", max);
}

int max_array(int a[], int elements)
{
	int index, max = 0;
	for (index = 0; index < elements; index++)
	{
		if (a[index] > max){
			max = a[index];
		}
	}
	return max;
}
