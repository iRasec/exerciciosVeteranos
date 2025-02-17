
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <biblioteca exercicio 5.h>
#include "Utils.h"
int main()
{
    int a, b;
    PDPilha ppilhaInt = criarPilha();
    PDPilha ppilhaInt2 = criarPilha();

    do
    {
    printf("\nde o valor pra formacao da lista : ");
    scanf("%d",&a);
    empilharInfo(PpilhaInt,alocaInt(a));

    }while(a!=0);
    do
    {
    printf("\nde o valor pra formacao da lista2 : ");
    scanf("%d",&b);
    empilharInfo(PpilhaInt2,alocaInt(a));

    }while(a!=0);

    void *info = desempilharInfo(pPilhaInt);
    printf("\nDesempilhou o inteiro = %d \n", *((int*)info));

    while (pilhaVazia(pPilhaInt)==0){
        info = desempilharInfo(pPilhaInt);
        printf("\nDesempilhou o inteiro = %d \n", *((int*)info));
    }
    r = contida(PpilhaInt, PpilhaInt2, comparaInt);
    if (r!=0)
        printf("\nContida\n");
    else
        printf("\nNao contida \n");
    break;

}
