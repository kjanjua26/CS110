#include <stdio.h>
#include <ctype.h>

const int MAXSIZE=100;

char* encrypt(unsigned char[], int);
void decrypt(unsigned char[], int);

int showMenu();

int main()
{

char c;
char choice,s[MAXSIZE];

while(1)
{
showMenu();

scanf("%c",&choice);

if((choice=='e')||(choice=='E'))
{
  puts("Input text to encrypt : ");
  fflush(stdin); //buffer overflow
  gets(s);
  encrypt(s, 3);
}
else if((choice=='d')||(choice=='D'))
{
  puts("Input text to decrypt->");
  fflush(stdin); //avoid buffer overflow
  gets(s);
  decrypt(s, 3);
}
else
break;
}
char *encrypt(unsigned char z[], int key)
{
	int i,value;
	int cipher_text = strlen(z);

	for(int c = 0 ; c <= cipher_text ; c++){
		if(z[c] > 64 && z[c] < 91){
			z[c] += key;
			value = z[c];
			if(value > 90){
				z[c] = value - 26;
			}
		}
		if(z[c] >96 && z[c] < 123){
			z[c] += key ;
			value = z[c];
			if(value > 122){
				z[c] = value - 26;
			}
		}
	}
	return z;
}
void decrypt(unsigned char z[], int key){
	int c;
        for (c = 0; c < strlen(z); c++){
		if (z[c] >= 'a' && z[c] <= 'z'){
            z[c] = z[c] - key;
            if ((z[c] < 'a') && ( z[c] >= 72 ))
            {
                z[c] = z[c] + 26;
            }
            }
    else if (z[c] >= 'A' && z[c] <= 'Z'){
                z[c] = z[c] - key;
                    if ((z[c] < 'A') && ( z[c] >= 40 ))
                {
                    z[c] = z[c] + 26;
                }
                }
        }
        printf("%s", z);

}

return 0;
}

int showMenu()
{
puts("To encrypt, input e or E\n");
puts("To decrypt, input d or D\n");
puts("To exit, input any other letter\n");
puts("Your choice:->\n");
return 0;
}
