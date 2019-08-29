#include<stdio.h>
#include<stdlib.h>
#include "ListaDinamica.h"

void InicializaLista(TipoLista *L) {
	(*L).Primeiro = NULL;
	(*L).Ultimo = NULL;
	printf("Criou a lista\n");
}

void InsereLista(TipoLista *L, TipoItem I) {

	TipoApontador P;
	
	P = (TipoApontador) malloc(sizeof(TipoNo));
	if (P == NULL) {
		printf("NAO FOI POSSIVEL INSERIR O ITEM: MEMORIA CHEIA\n");
		return;
	}
	
	P->Item = I;
	P->prox = NULL;
	if (ListaVazia(L)) {
		L->Primeiro = P;
		L->Ultimo = P;
	} else {
		L->Ultimo->prox = P;
		L->Ultimo = P;
	}
	

	printf("Item inserido: %d\n", I.Chave);
}

TipoApontador PesquisaLista(TipoLista *L, TipoChave C) {

	TipoApontador P;
	
	P = L->Primeiro;
	while(P != NULL) {
		//printf("Pesquisa passando por %d\n", P->Item.Chave);
		if (P->Item.Chave == C)
			return P;
		P = P->prox;
	}
	
	return NAO_ENCONTRADO;
}


int static RemoveListaPosicao(TipoLista *L, TipoApontador P) {

	if (P == NAO_ENCONTRADO)
		return POSICAOINVALIDA;

	// unico elemento na lista
	if (P == L->Primeiro && L->Primeiro == L->Ultimo) {
		L->Primeiro = NULL;
		L->Ultimo = NULL;
		free(P);
		return SEMERRO;
	}
	
	// Remove do inicio
	if (P == L->Primeiro) {
		L->Primeiro = L->Primeiro->prox;
		free(P);
		return SEMERRO;
	}
	
	// Remove no meio da lista
	TipoApontador aux = L->Primeiro;
	while(aux->prox != NULL && aux->prox != P) {
		aux = aux->prox;
	}
	
	aux->prox = P->prox;
	// se o removido estava no fim
	if (aux->prox == NULL)
		L->Ultimo = aux;
	
	free(P);
	
	return SEMERRO;
	
}

void RemoveLista(TipoLista *L, TipoChave C) {	
	TipoApontador P = PesquisaLista(L, C);	
	int r = RemoveListaPosicao(L, P);
	if (r != POSICAOINVALIDA)
		printf("Removeu elemento\n");
	else
		printf("Remocao deu ruim\n");
}

void ImprimeLista(TipoLista *L) {
	
	TipoApontador P = L->Primeiro;

	int i = 0;
	while(P != NULL) {
		if (P->prox != NULL)
			printf("%d: Chave=%d, Proximo=%d\n", i, P->Item.Chave, P->prox->Item.Chave);
		else
			printf("%d: Chave=%d, Proximo=NULO\n", i, P->Item.Chave);
		P = P->prox;
		i++;
	}
	
}

int ListaVazia(TipoLista *L) {
	if (L->Primeiro == NULL)
		return 1;
	else
		return 0;
}