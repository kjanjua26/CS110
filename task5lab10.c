#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdio.h>
int max_array(int a[], int elements);
int loc(int a[], int elements);
int main()
{
    printf("\nArray Games Start!\n");
	int size = 10, i, max, location;
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
	printf("}\n");
	max = max_array(a, size);
	location = loc(a, size);
	printf("The maximum value in array is: %d\n", max);
	printf("The location of maximum element is: %d\n", location); //considering that indexing starts from 0.
}


int max_array(int a[], int elements)
{
	int index, max = 0, loc;
	for (index = 0; index < elements; index++)
	{
		if (a[index] > max){
			max = a[index];
		}
	}
	return max;
}
int loc(int a[], int elements)
{
	int index, max = 0, loc;
	for (index = 0; index < elements; index++)
	{
		if (a[index] > max){
			max = a[index];
			loc = index;
		}
	}
	return loc;
}
