#include<stdio.h>
#include<stdlib.h>
#include "ListaDinamica.h"

int main() {
    TipoLista L;
    TipoItem item;

    InicializaLista(&L);

    item.Chave = 5;
    InserePrimeiroLista(&L, item);

	item.Chave = 1;
    InserePrimeiroLista(&L, item);

	ImprimeLista(&L);

    item.Chave = 3;
    InserePrimeiroLista(&L, item);
	
    item.Chave = 0;
    InserePrimeiroLista(&L, item);

	ImprimeLista(&L);
	
	PesquisaLista(&L, 5);
    RemoveLista(&L, 3);
    RemoveLista(&L, 5);
	
	ImprimeLista(&L);

	TipoApontador P = L;
	while(P != NULL) {
		L = L->prox;
		printf("Limpando\n");
		free(P);
		P = L;
	}
	
	return 0;
}
