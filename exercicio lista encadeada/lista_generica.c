#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include "biblioteca _lista_generica.h.h"
#include "Utils.h"
int main()
{
    PDlista listanumero;
    listanumero = criarlista();

    PDlista listaDatas;
    listaDatas = criarlista();

    PDlista copialista;
    copialista = criarlista();

    PDlista listaunida;
    listaunida = criarlista();

    PDlista listaintercecao;
    listaintercecao = criarlista();

    PDlista novalista;
    novalista = criarlista();

    PDlista listainvertida;
    listainvertida = criarlista();

     PDlista listacomplemento;
    listacomplemento = criarlista();

    int a,r,opc,opc2, dia, mes , ano, diap, mesp, anop,posicao;

    printf("\nqual vai ser tipo ?\n1-int\n2-datas\ndigite o numero correspondente-");
    scanf("%d",&opc);

    switch(opc){

    case 1 :
    do
    {
    printf("\nde o valor pra formacao da lista : ");
    scanf("%d",&a);
    incluirinfo(listanumero,alocaInt(a));

    }while(a!=0);

    while(1){

    printf("\nQual sera a mudanca da lista ?\n 01 - Imprime lista \n 02 - Duplicar lista \n 03 - Excluir info \n 04 - Incluir info no Inicio \n 05 - Contem info \n 06 - Incluir info no meio \n 07 - Incluir info base \n 08 - Dividir lista \n 09 - Soma info \n 10 - Unirlista \n 11 - Destruirlista \n 12 - Intercecaolista \n 13 - Novalista \n 14 - Contida \n 15 - InverterLista \n 16 - Complemento\nDigite...");
    scanf("%d",&opc2);
    switch(opc2){

    case 1 :
    printf("\n");
    imprimelista(listanumero, imprimeInt);
    printf("\n");
    break;


    case 2 :
    printf("\n");
    copialista = copialistas(listanumero, alocaInfoInt);
    imprimelista(copialista, imprimeInt);
    printf("\n");
    break;

    case 3 :
    printf("digite o valor a ser excluido: ");
    scanf("%d",&a);
    excluirinfo(listanumero, &a, comparaInt);
    imprimelista(listanumero, imprimeInt);
    printf("\n");
    break;


    case 4 :
    printf("\nDe o valor pra inclusao do primeiro valor da lista : ");
    scanf("%d",&a);
    incluirinfoinicio(listanumero,alocaInt(a));
    imprimelista(listanumero, imprimeInt);
    printf("\n");
    break;


    case 5 :
    printf("\nInforme um valor para verificacao, se esta contida: ");
    scanf("%d",&a);
    r = contemInfo(listanumero, alocaInt(a), comparaInt);
    if (r!=0)
        printf("contem\n");
    else
        printf("nao contem\n");
    break;

    case 6 :
    printf("\nDe o valor pra inclusao do valor no meio da lista : ");
    scanf("%d",&a);
    printf("\nDe a posicao do numero : ");
    scanf("%d",&posicao);
    incluirinfomeio(listanumero, alocaInt(a), posicao);
    imprimelista(listanumero, imprimeInt);
    printf("\n");
    break;


    case 7 :
    printf("\nDe o valor pra inclusao do valor no meio da lista usando um numero : ");
    scanf("%d",&a);
    printf("\nDe o valor que sera a posicao da lista : ");
    scanf("%d",&posicao);
    incluirinfobase(listanumero, alocaInt(a), alocaInt(posicao), comparaInt);
    imprimelista(listanumero, imprimeInt);
    printf("\n");
    break;

    case 8 :
    printf("\nDe a posicao do numero : ");
    scanf("%d",&posicao);
    dividirlista(listanumero, posicao);
    printf("\n");
    break;


    case 9 :
    somainfo(listanumero,somaInt,imprimesomaInt);
    printf("\n");
    break;

    case 10 :
    listaunida = unirlista(listanumero, copialista, comparaInt);
    imprimelista(listaunida, imprimeInt);
    printf("\n");
    break;

    case 11 :
        destruirlista(listanumero);
        printf("\nLista destruida !!");
        printf("\n");
    break;

    case 12 :
        listaintercecao = intercecaolista(listanumero, copialista, comparaInt);
        imprimelista(listaintercecao, imprimeInt);
    break;

    case 13 :
    do{
    printf("\nde o valor pra formacao da lista : ");
    scanf("%d",&a);
    novalista = listanova(novalista, alocaInt(a));
    }while(a!=0);
    imprimelista(novalista, imprimeInt);
    break;

    case 14 :
        r = contida(listanumero, novalista, comparaInt);
    if (r!=0)
        printf("\nContida\n");
    else
        printf("\nNao contida \n");
    break;

    case 15 :
        printf("\n");
        listainvertida = inverterlista(listanumero);
        imprimelista(listainvertida, imprimeInt);
        printf("\n");
        break;
    case 16 :
        listacomplemento = complemento(listanumero, novalista, comparaInt);
        imprimelista(listacomplemento, imprimeInt);
        break;

   /* case 17 :
        printf("\nde o valor pra decompor : ");
        scanf("%d",&a);
        listadecomposta = decompor(a, decomporInt);
*/
    default :
    printf("\n ainda n foi implementado essa funcao \n digite novamente \n");
    }
    }

    case 2 :

    do
    {
    printf("\ndigite uma data (00/00/00 encerra ) : ");
    printf("\nDia-");
    scanf("%d",&dia);
    printf("\nMes-");
    scanf("%d",&mes);
    printf("\nAno-");
    scanf("%d",&ano);
    incluirinfo(listaDatas,alocaData(dia,mes,ano));

    }while(dia!=0 && mes!=0 && ano!=0);
    while(1){

    printf("qual sera a mudanca da lista ?\n 1 - imprime lista \n 2 - duplicar lista \n  3 - excluir info \n 4 - incluir info no inicio \n 5 - contem info \n 6 - incluir info no meio \n 7 - incluir info base \n 8 - dividir lista \n 9 - soma info \n 10 - break \nDigite...");
    scanf("%d",&opc2);
    switch(opc2){

    case 1 :
    imprimelista(listaDatas, imprimeData);

    break;


    case 3 :
    printf("digite a data a ser excluida: ");
    printf("\nDia-");
    scanf("%d",&dia);
    printf("\nMes-");
    scanf("%d",&mes);
    printf("\nAno-");
    scanf("%d",&ano);
    excluirinfo(listaDatas, alocaData(dia,mes,ano), comparaData);
    imprimelista(listaDatas, imprimeData);
    break;


    case 4 :
    printf("\nDe o valor pra inclusao da primeira data da lista : ");
    printf("\nDia-");
    scanf("%d",&dia);
    printf("\nMes-");
    scanf("%d",&mes);
    printf("\nAno-");
    scanf("%d",&ano);
    incluirinfoinicio(listaDatas,alocaData(dia,mes,ano));
    imprimelista(listaDatas, imprimeData);
    break;

    case 5 :
    printf("\nInforme uma data para verificacao, se esta contida: ");
    printf("\nDia-");
    scanf("%d",&dia);
    printf("\nMes-");
    scanf("%d",&mes);
    printf("\nAno-");
    scanf("%d",&ano);
    r = contemInfo(listaDatas, alocaData(dia,mes,ano), comparaData);
    if (r!=0)
        printf("contem");
    else
        printf("nao contem");
    break;

    case 6 :
    printf("\nDe o valor pra inclusao da data no meio da lista : ");
    printf("\nDia-");
    scanf("%d",&dia);
    printf("\nMes-");
    scanf("%d",&mes);
    printf("\nAno-");
    scanf("%d",&ano);
    printf("\nDe a posicao da data: ");
    scanf("%d",&posicao);
    incluirinfomeio(listaDatas, alocaData(dia, mes, ano), posicao);
    imprimelista(listaDatas, imprimeData);
    break;

    case 7 :

    printf("\nDe o valor pra inclusao da data da base da lista : ");
    printf("\nDia-");
    scanf("%d",&dia);
    printf("\nMes-");
    scanf("%d",&mes);
    printf("\nAno-");
    scanf("%d",&ano);
    printf("\nDe o valor q deve ser encontrado da data: ");
     printf("\nDia-");
    scanf("%d",&diap);
    printf("\nMes-");
    scanf("%d",&mesp);
    printf("\nAno-");
    scanf("%d",&anop);
    incluirinfobase(listaDatas, alocaData(dia, mes, ano), alocaData(diap, mesp, anop), comparaData);
    break;

    case 10 :

        break;

    default :
    printf("\n ainda n foi implementado essa funcao \n digite novamente \n");
            }
        }
    }
}

