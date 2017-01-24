#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
float avg(int a[], int elem);
float dev(int a[], int eles);
float var(int a[], int ele);

int main(){

	printf("\nArray Games Start!\n");
	printf("\n");
	int size, i;
	float avgs, variance, sdev;
	size = 5;
	int a[30];
	printf("Now, enter your marks for %d courses.\n", size);

	for (i = 0; i < size; i++)
	{
		printf("Enter Mark for Course # %d\n", i + 1);
		scanf("%d", &a[i]);
	}
	printf("\n");
	printf("{");
	for (i = 0; i < size; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("}");
	avgs = avg(a, size);
	printf("\nThe average of your marks is: %.2f\n", avgs);
	variance = var(a, size);
	printf("The variance is: %.2f\n", variance);
	sdev = dev(a, size);
	printf("The standard deviation is: %.2f\n", sdev);
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
float var(int a[], int ele)
{
	int index;
	float variance = 0.0, sum = 0.0;
	float avgs, res = 0.0, locAvg;
	avgs = avg(a, 5);
	for (index = 0; index < ele; index++)
	{
		res = avgs - a[index];
		res = res * res;
		sum += res;
	}
	locAvg = sum / (float)ele;
	return locAvg;
}
float dev(int a[], int eles)
{
    float standardDev, variance;
    variance = var(a, 5);
    standardDev = sqrt(variance);
    return standardDev;
}


