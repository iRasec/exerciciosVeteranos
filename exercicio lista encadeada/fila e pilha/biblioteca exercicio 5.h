
typedef struct noh  Noh;
typedef Noh*        pNoh;

/* descritor da lista */
typedef struct dLista  DLista;
typedef DLista*        pDLista;

typedef struct dFila  DFila;
typedef DFila*        pDFila;

typedef struct dPilha  DPilha;
typedef DPilha*        pDPilha;

struct dFila{
    pDLista pdLista;
};

struct dPilha{
    pDLista pdLista;
};
/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDPilha  criarPilha     ();
void     empilharInfo   (pDPilha, void *);
void*    desempilharInfo(pDPilha);
int      pilhaVazia     (pDPilha);
//-------------------------------------------
pDPilha criarPilha(){
    /* aloca memoria para o descritor */
    pDPilha pd = (pDPilha) malloc(sizeof(DPilha));
    /* o descritor da pilha tem os mesmos campos do descritor de lista */
    pd->pdLista = criarLista();
    return pd;
}
void empilharInfo(pDPilha pdPilha, void *info){

   if (pdPilha != NULL)
       incluirInfo(pdPilha->pdLista, info);
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
