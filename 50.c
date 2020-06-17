#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
//-------------------------------------ex 1 ----------------------------------------------------------
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
//-------------------------------------ex 2 ----------------------------------------------------------
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
//-------------------------------------ex 3 ----------------------------------------------------------
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
//-------------------------------------ex 4 ----------------------------------------------------------
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
//-------------------------------------ex 6 ----------------------------------------------------------
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
//-------------------------------------ex 7 ----------------------------------------------------------
char *mystrcat(char s1[], char s2[])
{
    int a = 0;
    int b = 0;

    while (s1[a] != '\0')
        a++;
    while (s2[b] != '\0')
    {
        s1[a + b] = s2[b];
        b++;
    }

    s1[a + b] = '\0';
    return s1;
}
//-------------------------------------ex 8 ----------------------------------------------------------
char *strcpy(char *dest, char source[])
{
    int a = 0;
    while (source[a] != '\0')
    {
        dest[a] = source[a];
        a++;
    }
    dest[a] = '\0';
    return dest;
}
//-------------------------------------ex 9 ----------------------------------------------------------
int mystrcmp(char s1[], char s2[])
{
    int r = 0;
    int i = 0;

    while ((s1[i] == s2[i]) && s1[i] && s2[i])
        i++;

    if (s1[i] < s2[i])
        r = -1;
    else if (s1[i] > s2[i])
        r = 1;
    else if (s1[i] == '\0' && s2[i] != '\0')
        r = -1;
    else if (s1[i] != '\0' && s2[i] == '\0')
        r = 1;
    else if (s1[i] == '\0' && s2[i] == '\0')
        r = 0;

    return r; // ou bastava dar return s1[i] - s2[i] em vez desta merda toda.
}
//-------------------------------------ex 10 ----------------------------------------------------------
char *mystrstr(char s1[], char s2[])
{

    int i = 0;
    int j = 0;
    while (s1[i] != s2[j] && s1[i] && s2[j])
        i++;
    char *a = &(s1[i]);
    while (s1[i] == s2[j] && s1[i] && s2[j])
    {
        i++;
        j++;
    }
    if (!s2[j])
        return a;
    else
        return NULL;
}
//-------------------------------------ex 11 ----------------------------------------------------------
void strrev(char s[])
{
    int i = 0;
    int a = 0;
    while (s[i])
        i++;
    int b = i;
    i--;
    while (a != i && a < i)
    {
        char temp;
        temp = s[a];
        s[a] = s[i];
        s[i] = temp;
        a++;
        i--;
    }
}
//-------------------------------------ex 12 ----------------------------------------------------------
void strnoV(char s[])
{
    int i = 0;
    int a = 0;
    while (s[i])
    {
        if (s[i] == 'a' || s[i] == 'A' ||
            s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' ||
            s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U')
        {
            a = i;
            while (s[a])
            {
                s[a] = s[a + 1];
                a++;
            }
        }
        else
            i++;
    }
}
//-------------------------------------ex 13 ----------------------------------------------------------
void truncW(char t[], int n)
{
    int i = 0;
    int a = 0;

    while (t[i])
    {
        if (t[i] == ' ' || t[i] == '\t' || t[i] == '\n')
        {
            a = 0;
            i++;
        }
        else
        {
            if (a < n)
            {
                a++;
                i++;
            }
            else
            {
                a = i;
                while (t[a])
                {
                    t[a] = t[a + 1];
                    a++;
                }
            }
        }
    }
}
//-------------------------------------ex 14 ----------------------------------------------------------
char charMaisfreq(char s[])
{
}
//-------------------------------------ex 15 ----------------------------------------------------------
int iguaisConsecutivos(char s[])
{
    int a = 0;
    int fin = 0;
    char temp = s[0];
    int i = 0;
    while (s[i])
    {
        if (s[i] == temp)
        {
            a++;
            i++;
        }
        else if (a > fin)
        {
            fin = a;
            a = 0;
            temp = s[i];
        }
        else
        {
            a = 0;
            temp = s[i];
        }
    }
    if (a > fin)
        fin = a;
    return fin;
}
//-------------------------------------ex 16 ----------------------------------------------------------
int difConsecutivos(char s[])
{
    int i;
    int cont = 0;
    int fin = 0;

    for (i = 0; s[i]; i++)
    {

        if (s[i] != s[i + 1])
            cont++;
        else if (cont > fin)
        {
            fin = cont;
            cont = 0;
        }
    }
    return fin;
}
//-------------------------------------ex 17 ----------------------------------------------------------
int maiorPrefixo(char s1[], char s2[])
{
    int fin = 0;
    int i = 0;
    while (s1[i] == s2[i])
    {
        fin++;
        i++;
    }
    return fin;
}
}
//-------------------------------------ex 18 ----------------------------------------------------------
int maiorSufixo(char s1[], char s2[])
{
    int i = 0;
    int b = 0;
    int fin = 0;
    while (s1[i])
        i++;
    while (s2[b])
        b++;
    i--;
    b--;
    while (s1[i] == s2[b])
    {
        fin++;
        i--;
        b--;
    }
    return fin;
}
//-------------------------------------ex 19 ----------------------------------------------------------
int sufPref(char s1[], char s2[])
{
    int i = 0;
    int a = 0;
    int fin = 0;
    while (s1[i])
    {
        if (s1[i] == s2[a])
        {
            a++;
            fin++;
        }
        else
        {
            a = 0;
            fin = 0;
        }
        i++;
    }
    return fin;
}
//-------------------------------------ex 20 ----------------------------------------------------------
int contaPal(char s[])
{
    int i = 0;
    int fin = 0;
    while (s[i])
    {
        if ((s[i] != ' ' && s[i] != '\n' && s[i] != '\t') && (s[i + 1] == ' ' || s[i + 1] == '\0'))
        {
            fin++;
            i++;
        }
        else
            i++;
    }
    return fin;
}
//-------------------------------------ex 21 ----------------------------------------------------------
int contaVogais(char s[])
{
    int fin = 0;
    int i = 0;
    while (s[i])
        if (s[i] == 'a' || s[i] == 'A' ||
            s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' ||
            s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U')
        {
            fin++;
            i++;
        }
        else
            i++;
    return fin;
}
//-------------------------------------ex 22 ----------------------------------------------------------
int contida(char a[], char b[])
{
    int y = 0;
    int i;
    int x;
    for (i = 0; a[i]; i++)
    {
        y = 0;
        for (x = 0; b[x] && (y == 0); x++)
        {
            if (a[i] == b[x])
                y = 1;
        }
        if (y == 0)
            return 0;
    }
    return 1;
}
//-------------------------------------ex 23 ----------------------------------------------------------
int palindroma(char s[])
{
    int i = 0;
    int j;
    while (s[i])
        i++;
    i--;
    int r = 1;
    for (j = 0, i; j <= i && r == 1; j++, i--)
    {
        if (s[i] != s[j])
            r = 0;
    }
    return r;
}
//-------------------------------------ex 24 ----------------------------------------------------------
int remRep(char x[])
{
    int i = 0;
    while (x[i])
    {

        if (x[i] == x[i + 1])
        {
            int j = i;
            while (x[j])
            {
                x[j] = x[j + 1];
                j++;
            }
        }
        else
            i++;
    }
    return i;
}
//-------------------------------------ex 25 ----------------------------------------------------------
int limpaEspacos(char t[])
{
    int i;
    for (i = 0; t[i]; i++)
    {
        if (t[i] == ' ' && t[i + 1] == ' ')
        {
            int j = i;
            while (t[j])
            {
                t[j] = t[j + 1];
                j++;
            }
            i--;
        }
    }
    return i;
}
//-------------------------------------ex 26 ----------------------------------------------------------
void insere(int v[], int N, int x)
{
    int i;
    for (i = 0; i <= N; i++)
        ;
    int j = N + 1;
    while (j > i)
    {
        v[j] = v[j - 1];
        j--;
    }
    v[i] = x;
}
//-------------------------------------ex 27 ----------------------------------------------------------
void merge(int r[], int a[], int b[], int na, int nb)
{
    int i = 0;
    int j = 0;
    int n = 0;

    while (i < na && j < nb)
    {
        if (a[i] <= b[j])
        {
            r[n] = a[i];
            i++;
            n++;
        }
        else
        {
            r[n] = b[j];
            j++;
            n++;
        }
    }
    if (i == na)
    {
        while (j < nb)
        {
            r[n] = b[j];
            n++;
            j++;
        }
    }
    else
    {
        while (i < na)
        {
            r[n] = a[i];
            n++;
            i++;
        }
    }
}
//-------------------------------------ex 28 ----------------------------------------------------------
int crescente(int a[], int i, int j)
{
    int r = 1 for (i; (i < j) && r == 1; i++)
    {
        if (a[i] > a[i + 1])
            r = 0;
    }
    return r;
}
//-------------------------------------ex 29 ----------------------------------------------------------
int retiraNeg(int v[], int N)
{
    int ret = 0, i;
    int j;
    for (i = 0; i < N; i++)
    {
        if (v[i] < 0)
        {
            j = i;
            while (j < N)
            {
                v[j] = v[j + 1];
                j++;
            }
            i--;
            N--;
        }
        else
            ret++;
    }
    return ret;
}
//-------------------------------------ex 30 ----------------------------------------------------------
int menosFreq(int v[], int N)
{
    int i = 0;
    int cont = 1;
    int fin = 100;
    int ret = v[0];
    while (i < N)
    {
        if (v[i] == v[i + 1])
        {
            cont++;
            i++;
        }
        else if (cont < fin)
        {
            fin = cont;
            ret = v[i];
            cont = 1;
            i++;
        }
        else
        {
            cont = 1;
            i++;
        }
    }
    return ret;
}
//-------------------------------------ex 31 ----------------------------------------------------------
int maisFreq(int v[], int N)
{
    int i = 0;
    int cont = 1;
    int fin = 0;
    int ret = v[0];
    while (i < N)
    {
        if (v[i] == v[i + 1])
        {
            cont++;
            i++;
        }
        else if (cont > fin)
        {
            fin = cont;
            ret = v[i];
            cont = 1;
            i++;
        }
        else
        {
            cont = 1;
            i++;
        }
    }
    return ret;
}
//-------------------------------------ex 32 ----------------------------------------------------------
int maxCresc(int v[], int N)
{
    int i;
    int conta = 1;
    int tamanho = 0;
    for (i = 0; i < N; i++)
    {
        if (v[i] <= v[i + 1])
        {
            conta++;
        }
        else if (conta > tamanho)
        {
            tamanho = conta;
            conta = 1;
        }
        else
            conta = 1;
    }
    return tamanho;
}
//-------------------------------------ex 33 ----------------------------------------------------------
int elimRep(int v[], int n)
{
    int i, j;
    int z;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
            if (v[i] == v[j])
            {
                z = j;
                while (z < n)
                {
                    v[z] = v[z + 1];
                    z++;
                }
                n--;
                j--;
            }
    }
    return n;
}
//-------------------------------------ex 34 ----------------------------------------------------------
int elimRepOrd(int v[], int n)
{
    int i = 0;
    int z;
    while (i < n && n != 1)
    {
        if (v[i] == v[i + 1])
        {
            z = i;
            while (z < n)
            {
                v[z] = v[z + 1];
                z++;
            }
            n--;
        }
        else
            i++;
    }
    return n;
}
//-------------------------------------ex 35 ----------------------------------------------------------
//imcopleta
int comunsOrd(int a[], int na, int b[], int nb)
{
    // Função escaxe, os stores sao uns burros
}
//-------------------------------------ex 36 ----------------------------------------------------------
int comuns(int a[], int na, int b[], int nb)
{
    int i, j;
    int comum = 0;
    int con = 1;
    for (i = 0; i < na; i++)
    {
        for (j = 0; j < nb && con == 1; j++)
        {
            if (a[i] == b[j])
            {
                comum++;
                con = 0;
            }
        }
        con = 1;
    }
    return comum;
}
}
//-------------------------------------ex 37 ----------------------------------------------------------
int minInd(int v[], int n)
{
    int conta = v[0];
    int ret = 0;
    int i = 1;
    while (i < n)
    {
        if (v[i] < conta)
        {
            conta = v[i];
            ret = i;
        }
        i++;
    }
    return ret;
}
//-------------------------------------ex 38 ----------------------------------------------------------
void somasAc(int v[], int Ac[], int N)
{
    int i = 0;
    int acum = 0;
    while (i < N)
    {
        acum += v[i];
        Ac[i] = acum;
        i++;
    }
}
//-------------------------------------ex 39 ----------------------------------------------------------
int triSup(int N, float m[N][N])
{
    int i;
    int z;
    int r = 1;
    for (i = 0; i < N && r == 1; i++)
    {
        for (z = i; z >= 0 && r == 1; z--)
        {
            if (z < i && (m[i][z] != 0))
                r = 0;
        }
    }
    return r;
}
/*  A condição é sempre que o z for menor que o i.
1 1 1 1   1 1 1  1 1
0 1 1 1   0 1 1  0 1
0 0 1 1   0 0 1
0 0 0 1    
*/
//-------------------------------------ex 40 ----------------------------------------------------------
void transposta(int N, float m[N][N])
{
    int i, z, a;
    for (i = 0; i < N; i++)
    {
        for (z = i; z < N; z++)
        {
            a = m[i][z];
            m[i][z] = m[z][i];
            m[z][i] = a;
        }
    }
}
//-------------------------------------ex 41 ----------------------------------------------------------
void addTo(int N, int M, int a[N][M], int b[N][M])
{
    int i, z;
    for (i = 0; i < N; i++)
    {
        for (z = 0; z < M; z++)
            a[i][z] += b[i][z];
    }
}
//-------------------------------------ex 42 ----------------------------------------------------------
int unionSet(int N, int v1[N], int v2[N], int r[N])
{
    int i = 0;
    int comum = 0;
    while (i < N)
    {
        if (v1[i] == 0 && v2[i] == 0)
        {
            r[i] = 0;
        }
        else
            r[i] = 1;
        i++;
    }
    return i;
}
//-------------------------------------ex 43 ----------------------------------------------------------
int intersectSet(int N, int v1[N], int v2[N], int r[N])
{
    int i = 0;
    int comum = 0;
    while (i < N)
    {
        if (v1[i] == 1 && v2[i] == 1)
        {
            r[i] = 1;
        }
        else
            r[i] = 0;
        i++;
    }
    return i;
}
//-------------------------------------ex 44 ----------------------------------------------------------
int intersectMSet(int N, int v1[N], int v2[N], int r[N]) // Função de piça, jbb podes ir para o caralho
{
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
    return 0;
}
//-------------------------------------ex 45 ----------------------------------------------------------
int unionMSet(int N, int v1[N], int v2[N], int r[N]) // Outra função de merda, Jbb já sabes.

    //-------------------------------------ex 46 ----------------------------------------------------------
    int cardinalMSet(int N, int v[N])
{
    int i = 0;
    int conta = 0;
    while (i < N)
    {
        conta += v[i];
        i++;
    }
    return conta;
}
//-------------------------------------ex 47 ----------------------------------------------------------
typedef enum movimento
{
    Norte,
    Oeste,
    Sul,
    Este
} Movimento;

typedef struct posicao
{
    int x, y;
} Posicao;

Posicao posFinal(Posicao inicial, Movimento mov[], int N)
{
    int i = 0;
    while (i < N)
    {
        if (mov[i] == Norte)
        {
            inicial.y++;
            i++;
        }
        else if (mov[i] == Sul)
        {
            inicial.y--;
            i++;
        }
        else if (mov[i] == Este)
        {
            inicial.x++;
            i++;
        }
        else if (mov[i] == Oeste)
        {
            inicial.x--;
            i++;
        }
    }
    return inicial;
}
//-------------------------------------ex 48 ----------------------------------------------------------
int caminho(Posicao inicial, Posicao final, Movimento mov[], int N)
{

    int horiz = (final.x) - (inicial.x);
    int vertical = (final.y) - (inicial.y);
    int i = 0;
    if ((abs(horiz) + abs(vertical)) > 10)
        return -1;
    if (horiz < 0)
    {
        while (horiz != 0)
        {
            mov[i] = Oeste;
            i++;
            horiz++;
        }
    }
    else if (horiz > 0)
    {
        while (horiz != 0)
        {
            mov[i] = Este;
            i++;
            horiz--;
        }
    }
    if (vertical < 0)
    {
        while (vertical != 0)
        {
            mov[i] = Sul;
            i++;
            vertical++;
        }
    }
    else if (vertical > 0)
    {
        while (vertical != 0)
        {
            mov[i] = Norte;
            i++;
            vertical--;
        }
    }
    return i;
}
//-------------------------------------ex 49 ----------------------------------------------------------
int maiscentral(Posicao pos[], int N)
{
    int i = 0;
    float dist = 100;
    float temp;
    int ret;
    Posicao t;

    while (i < N)
    {
        t = pos[i];
        temp = sqrt(((t.x) * (t.x)) + ((t.y) * (t.y)));
        if (temp < dist)
        {
            dist = temp;
            ret = i;
            i++;
        }
        else
            i++;
    }
    return ret;
}
//-------------------------------------ex 50 ----------------------------------------------------------
int vizinhos(Posicao p, Posicao pos[], int N) // mais uma funcao de merda em que nao considera os vizinhos obliquos
{
    int viz = 0;
    int i = 0;
    int h, v;
    while (i < N)
    {
        h = abs(p.x - ((pos[i]).x));
        v = abs(p.y - ((pos[i]).y));
        //if (v == 1 && h == 1);
        if (v == 1 && h == 0)
            viz++;
        if (v == 0 && h == 1)
            viz++;
        i++;
    }
    return viz;
}