#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int arr[100];
int prime(long int);
int hcf(unsigned long long int, unsigned long long int);
unsigned long long int findd(unsigned long long int, unsigned long long int);
void input(char[] ,char []);

void input(char message[],char msg[]){

	for (int i = 0; i < strlen(message); i++){

		if (isalpha(message[i])){ message[i] = toupper(message[i]); }
	}
	printf("Input.  |");

	for (int i = 0; i < strlen(message); i++){
		printf("\'%2c\'|", message[i]);
	}

	printf("\n        |");

	for (int i = 0; i < strlen(message); i++){

		if (message[i] == ' ')  { msg[i] = 26; }
		else if (message[i] == '.')  { msg[i] = 27; }
		else msg[i] = (message[i] - 'A');
	}

	for (int i = 0; i < strlen(message); i++){

		printf("\'%2d\'|", msg[i]);
	}
	printf("\n");
}
void Output(char message[],char msg[]){
   printf("Output. |");

    for (int i = 0; i < strlen(message); i++){

		if (message[i] == ' ')  { msg[i] = 26; }
		else if (message[i] == '.')  { msg[i] = 27; }
		else msg[i] = (message[i] - 'A');
	}

	for (int i = 0; i < strlen(message); i++){

		printf("\'%2d\'|", msg[i]);
	}
	printf("\n");

	for (int i = 0; i < strlen(message); i++){

		if (isalpha(message[i])){ message[i] = toupper(message[i]); }
	}
printf("        |");
	for (int i = 0; i < strlen(message); i++)
        {
		printf("\'%2c\'|", message[i]);
	}

	//printf("\n        |");

}
void M(char message[]){
	printf("\n\n     M. |");

	for (int i = 0; i < strlen(message); i = i + 2)
	{
		printf("  %c%c |", message[i], message[i + 1]);
	}
	printf("\n");
}
void P(char msg[],char message[]){

	printf("     P. |");

	msg[strlen(message)] = 0;

	int j = 0;

	for (int i = 0; i < strlen(message); i=i+2){

		arr[j] = msg[i] * 100 + msg[i + 1];

		printf(" %4d|", msg[i] * 100 + msg[i + 1]);

		j++;
	}

	arr[j] = '\0';

}
int hcf(unsigned long long int a, unsigned long long int h) //Check if the number e is co-prime or not.
{
    unsigned long long int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}
unsigned long long int findd( unsigned long long e, unsigned long long phi) //To find the value of d.
{
	unsigned long long x, y, u, v, m, n, a, b, q, r;
	x = 0; y = 1;
	u = 1; v = 0;
	for (a = e, b = phi; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n)
	{
		q = b / a;
		r = b % a;
		m = x - (u * q);
		n = y - (v * q);
	}
	return m + x;
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
int prime(long int pr) { //Checking if the entered number is prime.
	int i, c;
	c = sqrt(pr);
	for (i = 2;i <= c; i++) {
		if(pr%i == 0)
		    return 0;
	}
	return 1;
}
int main()
{
    printf("+-----------------------------+\n");
	printf("| RSA Public-key Cryptosystem |\n");
	printf("+-----------------------------+\n");

    int k, i;
    int m_arr[30];
    char msg[100];
    char message[] = "ROME IS NOT BUILT IN ONE DAY";
    long int FirstPrime, SecPrime, check, n;
    unsigned long long int gcd, phi, e, d;
    printf("\n\n");
    printf("+-------------------+\n");
	printf("| I. Key Generation |\n");
	printf("+-------------------+\n");
    printf("Enter first prime number: ");
    scanf("%lu", &FirstPrime);
    check = prime(FirstPrime);
    if (check == 0){
        printf("Invalid Input\n");
        return 0;
    }
    printf("Enter second prime number: ");
    scanf("%lu", &SecPrime);
    check = prime(SecPrime);
    if (check == 0 || SecPrime == FirstPrime)
    {
        printf("Invalid Input.\n");
        return 0;
    }
    n = FirstPrime * SecPrime;
    phi = (FirstPrime -1) * (SecPrime -1);
    printf("F(n): %llu\n", phi);
    printf("Choose any number [1 < e < %d] that is co-prime to it: ", phi);
    scanf("%llu", &e);
    gcd = hcf(e, phi);
    if (gcd != 1)
    {
        printf("Invalid co-prime entered.\n");
        return 0;
    }
    d = findd(e, phi);
    printf("The d is: %llu\n", d);
    printf("The public key is: (%llu, %lu)\n", e, n);
    printf("The private key is: (%llu, %lu)\n", d, n);
	int key = 2;
	printf("\n\n");
	printf("+-------------------------+\n");
	printf("| II. Cipher and Decipher |\n");
	printf("+-------------------------+\n");

	input(message,msg);
	M(message);
	P(msg,message);

	printf("\n     C. |");

	for (int i = 0; arr[i] != '\0'; i++){

		unsigned  long long int num = 1;

		for (int j = 1; j <= e; j++){

			num = num * arr[i];
			num = num % 3233;
		}

		printf(" %4d|", num);
	}
	printf("\n     D. |"); //Decryption

	for (int i = 0; arr[i] != '\0'; i++){

		unsigned  long long int num = 1;

			num = pow(arr[i], 2753);
			arr[i] = arr[i] % 3233;
            printf(" %4d|", arr[i]);
	}
    M(message);
    Output(message, msg);
}
