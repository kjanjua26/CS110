#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdio.h>
int max_array(int a[], int elements);
int even_entries(int a[], int ele);
float avg(int a[], int elem);

int main(void)
{
	printf("\nArray Games Start!\n");
	int size, i;
	int max, entries;
	float avgs;
	printf("Size: ");
	scanf("%d", &size);
	int a[30];
	for (i = 0; i < size; i++)
	{
		printf("Enter Element # %d\n", i + 1);
		scanf("%d", &a[i]);
	}
	printf("\n");
	printf("{");
	for (i = 0; i < size; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("}");
	max = max_array(a, size);
	printf("\nThe max value is: %d\n", max);
	entries = even_entries(a, size);
	printf("\nThe even entries are: %d\n", entries);
	avgs = avg(a, size);
	printf("The average is: %.2f\n", avgs);
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
int even_entries(int a[], int ele)
{
	int index, even = 0;
	for (index = 0; index < ele; index++)
	{
		if ((a[index] % 2) == 0)
		{
			even++;
		}
	}
	return even;
}

float avg(int a[], int elem)
{
	int index;
	float sum = 0.0;
	float avg;

	for (index = 0; index < elem; index++)
	{
		sum = sum + a[index];
	}
	avg = sum / (float)elem;
	return avg;
}
