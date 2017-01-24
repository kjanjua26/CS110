#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void encryption(char[],int []);
void decryption(int[]);

void print(int[],int);
int power(int, int,int);
int main()
{
	char str[]="RSA CRYPTO";
	int e, d, n;
	int c_arr[30];



	encryption(str,c_arr);
	decryption(c_arr);
	getch();
}


void num_print(int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
}

int power(int m, int e,int n)
{
	unsigned long long int num=1;
	for (int i = 1; i <= e; i++)
	{
		num = num*m;
		num = num % n;
	}


	return num;
}

void encryption(char str[], int c_arr[30])
{
	int num_arr[30], p_arr[30];

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			num_arr[i] = str[i] - 6;
		else if (str[i] == '.')
			num_arr[i] = str[i] - 19;
		else
			num_arr[i] = str[i] - 65;

	}




	for (int i = 0; str[i] != '\0'; i++)
	{
		printf("%c\t", str[i]);
	}


	printf("\n");
	num_print(num_arr,10);



	for (int i = 0,j=0;j<(strlen(str)/2); i += 2,j++)
	{
		p_arr[j] = (num_arr[i] * 100) + num_arr[i + 1];
	}
	printf("\n");
	num_print(p_arr,5);


	for (int i = 0; i < (strlen(str) / 2); i++)
	{
		c_arr[i] = power(p_arr[i],17, 3233);
	}

	printf("\n");
	num_print(c_arr, 5);
}

void decryption(int c_arr[30])
{
	int d_arr[30],m_arr[30];
	char str[30];
	for (int i = 0; i < 5; i++)
	{
		d_arr[i] = power(c_arr[i],	2753, 3233);
	}
	printf("\n");
	num_print(d_arr, 5);

	for (int i = 0, j = 0; i < 5; i++, j+=2)
	{
		m_arr[j + 1] = d_arr[i] % 100;
		d_arr[i] = d_arr[i] / 100;
		m_arr[j ] = d_arr[i];
	}

	printf("\n");
	num_print(m_arr, 10);

	for (int i = 0;i<10; i++)
	{
		if (m_arr[i] == 26)
			str[i] = m_arr[i] + 6;
		else if (m_arr[i] == 27)
			str[i] = m_arr[i] + 19;
		else
			str[i] = m_arr[i] +65;

	}
	str[10] = '\0';

	printf("\n");

	for (int i = 0; i<strlen(str); i++)
	{
		printf("%c\t", str[i]);
	}


}
