#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

int ehPotenciaDeDois(int n)
{
    if (n == 1)
        return 0;

    if (n == 0)
        return 1;
    else
        return ehPotenciaDeDois(n%2);
}
int fat(int n)
{
    if (n==0)
        return 1;
    else
        return n*fat(n-1);
}
int pot(int n, int e)
{
    if (e==0)
        return 1;

    if (e>0)
        return n*pot(n,e-1);
}
int qdigitos(int n)
{
    if (n<10)
        return 1;
    else
        return 1 + qdigitos(n/10);
}
int sdigitos(int n)
{
    if (n<10)
        return n;
    else
        return n + sdigitos(n/10);
}
int cdigitos (int n, int k)
{
    if (n==k && n < 10)
        return 1;
    else
        if (n<10 && n!=k)
        return 0;

    if (n%10 == k)
        return 1 + cdigitos(n/10,k);
    else
        return 0 + cdigitos(n/10,k);
}
void binario(int n)
{
    if ( n == 0 )
        return 0;
    int resto = n %2;
    binario(n/2);
    printf("%d",resto);
}
int main ()
{
    int n,e,r;
    printf("digite (n) para verificar se eh potencia e dois: ");
    scanf("%d",&n);

    r = ehPotenciaDeDois(n);

    if(r != 0)
        printf ("\no numero %d eh potencia de dois ", n);
        else
        printf ("\no numero %d nao eh potencia de dois ", n);


}
