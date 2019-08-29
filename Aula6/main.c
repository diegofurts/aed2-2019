#include<stdio.h>
#include<stdlib.h>
#include "ListaDinamica.h"

int main() {
    TipoLista L;
    TipoItem item;

    InicializaLista(&L);

	printf("Lista vazia? %d\n", ListaVazia(&L));
	
    item.Chave = 5;
    InsereLista(&L, item);

	item.Chave = 1;
    InsereLista(&L, item);

	ImprimeLista(&L);

    item.Chave = 3;
    InsereLista(&L, item);
	
    item.Chave = 0;
    InsereLista(&L, item);

	ImprimeLista(&L);
	
	//PesquisaLista(&L, 5);
	
    RemoveLista(&L, 3);
    RemoveLista(&L, 5);
	
	ImprimeLista(&L);
	
	item.Chave = 15;
    InsereLista(&L, item);
	
	ImprimeLista(&L);
	
	RemoveLista(&L, 15);
	
	ImprimeLista(&L);

	/*TipoApontador P = L;
	while(P != NULL) {
		L = L->prox;
		printf("Limpando\n");
		free(P);
		P = L;
	}*/
	
	return 0;
}
