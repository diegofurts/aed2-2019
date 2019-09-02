#include<stdio.h>
#include<stdlib.h>
#include "SkipList.h"

int main() {

    TipoLista L;
    TipoItem item;

    InicializaLista(&L);

    item.Chave = 5;
    InsereLista(&L, item);
    
    printf("%d %d\n", L->Item.Chave, L->prox->Item.Chave);

	item.Chave = 1;
    InsereLista(&L, item);
    
    printf("%d %d %d\n", L->Item.Chave, L->prox->Item.Chave, L->prox->prox->Item.Chave);

    item.Chave = 3;
    InsereLista(&L, item);
    
    printf("%d %d %d\n", L->Item.Chave, L->prox->Item.Chave, L->prox->prox->Item.Chave);
	
    item.Chave = 0;
    InsereLista(&L, item);
    
    item.Chave = 3;
    InsereLista(&L, item);
    
    TipoApontador P = PesquisaLista(&L, 1);
    if (P!=NULL)
        printf("Encontrou %d\n", P->Item.Chave);
    else
        printf("Algo errado nao esta certo\n");
    
	
	/*
    RemoveLista(&L, 3);
    RemoveLista(&L, 5);

	TipoApontador P = L;
	while(P != NULL) {
		L = L->prox;
		printf("Limpando\n");
		free(P);
		P = L;
	}*/
	
	return 0;
}
