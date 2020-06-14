#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

void ex1()
{
    int i;
    int max = INT32_MIN; // numero menor com 32 bits

    printf("Insira uma sequencia: \n");

    do
    {
        scanf("%d", &i);
        if (max < i && i)
            max = i;
    } while (i != 0);

    printf("Maximo %d", max);
}
void ex2()
{
    int i, soma, contador;
    soma = 0;
    contador = 0;

    printf("Insira uma sequencia: \n");

    do
    {
        scanf("%d", &i);
        soma += i;
        if (i != 0)
            contador++;
    } while (i != 0);

    printf("Media =   %d", soma / contador);
}

void ex3()
{
    int i, max1, max2;
    max1 = INT32_MIN;
    max2 = INT32_MIN;
    i = 1; // apenas para o i nao ser igual a zero

    printf("Insira uma sequencia: \n");

    while (i != 0)
    {
        scanf("%d", &i);
        if (i > max1 && i)
            max1 = i;
        else if (i > max2 && i)
            max2 = i;
    }

    printf("2º maior elemento =   %d", max2);
}

int bitsUm(unsigned int n)
{
    int bits = 0;

    while (n > 0)
    {
        bits += n % 2;
        n /= 2;
    }
    return bits;
}


int qDig(unsigned int n)
{
    int n_algarismos = 1;
    while (n / 10 > 0)
    {
        n_algarismos++;
        n /= 10;
    }
    return n_algarismos;
}

char *mystrcat(char s1[], char s2[]) {
int a = 0;
int b = 0;

while (s1[a] != '\0') a++;
while (s2[b] != '\0') {
    s1[a+b] = s2[b];
    b++;
}

s1[a+b] = '\0';
return s1;
}

char *strcpy (char *dest, char source[]) {
int a = 0;
while (source[a] != '\0') {
    dest[a] = source[a];
    a++;
}
dest[a] = '\0';
return dest;
}

int mystrcmp(char s1[], char s2[]) {
int r = 0;
int i = 0;

while ((s1[i] == s2[i]) && s1[i] && s2[i]) i++;

if (s1[i] < s2[i]) r = -1;
else if (s1[i] > s2[i]) r = 1;
else if (s1[i] == '\0' && s2[i] != '\0') r = -1;
else if (s1[i] != '\0' && s2[i] == '\0') r = 1;
else if (s1[i] == '\0' && s2[i] == '\0') r = 0;

return r; // ou bastava dar return s1[i] - s2[i] em vez desta merda toda.
}


