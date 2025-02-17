typedef struct noh Noh;
typedef Noh *      pNoh;

//     Descritor da lista

typedef struct dlista Dlista;
typedef Dlista  *    PDlista;

//     operacoes

typedef void (*funcaoimpressao) (void*);
typedef int (*funcaoComparacao)(void*,void*);
typedef void* (*funcaosoma)(void*,void*);
typedef void* (*funcaoAlocacao) (void*);
typedef void (*funcaoimprimesoma) (void*);
//typedef void (*funcaodecomposicao) (void*);
PDlista criarlista ();

void incluirinfo (PDlista, void*);
void incluirinfoinicio(PDlista,void*);
void incluirinfomeio(PDlista,void*, int);
void incluirinfobase(PDlista,void*, void*,funcaoComparacao);
void somainfo(PDlista, funcaosoma, funcaoimprimesoma);


int excluirinfo(PDlista, void*, funcaoComparacao);
int conteminfo (PDlista,void*,funcaoComparacao);
int imprimirlista(PDlista,funcaoimpressao);
PDlista copialistas (PDlista, funcaoAlocacao);
PDlista dividirlista (PDlista, int);
PDlista unirlista(PDlista, PDlista, funcaoComparacao);
PDlista intercecaolista(PDlista, PDlista, funcaoComparacao);
PDlista listanova(PDlista, void*);
PDlista inverterlista(PDlista pd);
void destruirlista(PDlista);
int contida(PDlista, PDlista, funcaoComparacao);
PDlista complemento (PDlista, PDlista, funcaoComparacao fc);
struct noh
{
    void * info;
    struct noh *prox;
};

struct dlista
{
    struct noh * primeiro;
    struct noh * ultimo;
    int quantidade;
};
PDlista criarlista()
{
   PDlista pd = malloc(sizeof(Dlista));

   pd->primeiro = NULL;
   pd->ultimo = NULL;
   pd->quantidade = 0;

   return pd;
}
void incluirinfo(PDlista pd, void * novainfo){

    pNoh novonoh;

    novonoh = malloc(sizeof(Noh));
    novonoh->info = novainfo;
    pd->quantidade++;

    if(pd->primeiro == NULL){
        pd->primeiro = novonoh;
    }
    novonoh->prox = NULL;

    if(pd->ultimo != NULL){
    pd->ultimo->prox = novonoh;
    }
    pd->ultimo = novonoh;
}
void imprimelista (PDlista pd,funcaoimpressao pfi)
{
struct noh *atual;

    atual = pd->primeiro;
    while(atual != NULL)
    {
        pfi(atual->info);
        atual = atual->prox;
    }
}

int excluirinfo(PDlista pd, void* novainfo, funcaoComparacao fc)
{
    //excluir um valor da lista

    struct noh *atual;
    struct noh *anterior = NULL;

    atual = pd->primeiro;

while(atual != NULL)
    {
        if (fc(atual->info, novainfo) == 0)
        {
            if (anterior == NULL)
            {
                pd->primeiro = atual->prox;
            }
            else
            {
            anterior->prox = atual->prox;
            }
            free(atual);
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return 0;
}
void incluirinfoinicio(PDlista pd,void * novainfo)
{
    pNoh novonoh;

    novonoh = malloc(sizeof(Noh));
     novonoh->info = novainfo;

    novonoh->prox = pd->primeiro;
    pd->primeiro = novonoh;

    pd->quantidade++;

    if(pd->ultimo == NULL){
    pd->ultimo = novonoh;
    }
}
void incluirinfomeio(PDlista pd, void * novainfo, int posicao)
{
    struct noh *atual;
    struct noh *anterior = NULL;
    pNoh novonoh;
    int cont = 1 ;

    atual = pd->primeiro;
    novonoh = malloc(sizeof(Noh));
    novonoh->info = novainfo;

 while(atual != NULL)
    {
        if (posicao == cont)
        {
            break;
        }
        anterior = atual;
        atual = atual->prox;
        cont++;
    }

     anterior->prox = novonoh;
     novonoh->prox = atual;
}
void incluirinfobase (PDlista pd, void * novainfo, void *infobase, funcaoComparacao fc)
{
    int posBase;

   posBase = contemInfo(pd, infobase, fc);

   if(posBase > 0)
      incluirinfomeio(pd, novainfo, posBase);


}
int contemInfo(PDlista pd, void* novaInfo, funcaoComparacao fc){

  struct noh* atual;
  int cont = 1;

  atual = pd->primeiro;

  while(atual != NULL){
    if(fc(atual->info, novaInfo) == 0)
    {
        return cont;
    }
    cont++;
    atual = atual->prox;
  }
    return 0;
}
PDlista copialistas(PDlista pd , funcaoAlocacao fa)
{
    PDlista copia;
    copia = criarlista();

    pNoh atual;
    atual = pd->primeiro;
    while (atual != NULL)
    {
        void * infocopia = fa(atual->info);
        incluirinfo(copia, infocopia);
        atual = atual->prox;
    }
    return copia;
}
PDlista dividirlista (PDlista listaoriginal,int posicao )
{
    PDlista novalista;
    novalista = criarlista();


    pNoh atual = listaoriginal->primeiro;

int cont = 1;
while(cont<posicao){
    atual = atual->prox;
    cont++;
}
novalista->primeiro = atual->prox;
atual->prox = NULL;
novalista->ultimo = listaoriginal->ultimo;
listaoriginal->ultimo = atual;
novalista->quantidade = listaoriginal->quantidade - posicao;
listaoriginal->quantidade = posicao;
    return novalista;
}
void somainfo (PDlista pd, funcaosoma fs, funcaoimprimesoma is)
{
    struct noh *atual;

    void * soma = NULL;

    atual = pd->primeiro;
    while(atual != NULL)
    {
        soma = fs(soma, atual->info);
        atual = atual->prox;
    }
    is(soma);

}
PDlista unirlista(PDlista pd , PDlista nd, funcaoComparacao fc)
{
    PDlista listaunida;
    listaunida = criarlista();

    pNoh atual = pd->primeiro;
    pNoh atualc = nd->primeiro;

    while(atual != NULL)
    {
        if (contemInfo(listaunida, atual->info, fc) == 0)
        incluirinfo(listaunida, atual->info);
        atual = atual->prox;
    }
    while(atualc != NULL)
    {
        if (contemInfo(listaunida, atualc->info, fc) == 0)
        incluirinfo(listaunida, atualc->info);
        atualc = atualc->prox;
    }
    return listaunida;

}
void destruirlista(PDlista pd)
{

    pNoh atual = pd->primeiro;

    while(atual != NULL)
    {
        free(atual->info);
        atual = atual->prox;
    }

}
PDlista intercecaolista(PDlista pd , PDlista nd, funcaoComparacao fc)
{
    PDlista listaintercecao;
    listaintercecao = criarlista();

    pNoh atual = pd->primeiro;
    pNoh atualc = nd->primeiro;

    while(atual != NULL)
    {
        if (contemInfo(listaintercecao, atual->info, fc) == 0)
        incluirinfo(listaintercecao, atual->info);
        atual = atual->prox;
    }
    while(atualc != NULL)
    {
        if (contemInfo(listaintercecao, atualc->info, fc) == 0)
        incluirinfo(listaintercecao, atualc->info);
        atualc = atualc->prox;
    }
    return listaintercecao;

}
PDlista listanova(PDlista pd, void * novainfo)
{
    incluirinfo(pd, novainfo);
}
int contida(PDlista pd, PDlista nd, funcaoComparacao fc)
{
    int r = 0;
    pNoh atual = pd->primeiro;
    pNoh atualc = nd->primeiro;

    while(atual != NULL)
    {
        r += contemInfo(nd, atual->info, fc);

        atual = atual->prox;
    }
        return r;
}
PDlista inverterlista(PDlista pd)
{
    PDlista ListaInvertida;
    ListaInvertida = criarlista();

    pNoh atual = pd->primeiro;

    while(atual != NULL)
    {
        incluirinfoinicio(ListaInvertida, atual->info);

        atual = atual->prox;
    }


return ListaInvertida;
}
PDlista complemento (PDlista l1, PDlista l2, funcaoComparacao fc)
{
    int r;
    PDlista comple;
    comple = criarlista();

    pNoh atual = l1->primeiro;
    while(atual != NULL)
    {
        r = contemInfo(l2, atual->info, fc);
        if(r != 0 )
        incluirinfo(comple, atual->info);

        atual = atual->prox;
        r=0;
    }
    return comple;
}
//PDlista decompor (void * n, funcaodecomposicao)
