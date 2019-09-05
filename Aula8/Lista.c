#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"

void InicializaLista(TipoLista *L) {
	*L = NULL;
}

void InsereLista(TipoLista *L, TipoItem I) {

	TipoApontador P;
	
	P = (TipoApontador) malloc(sizeof(TipoNo));
	if (P == NULL) {
		printf("NAO FOI POSSIVEL INSERIR O ITEM: MEMORIA CHEIA\n");
		return;
	}
	
	P->Item = I;
	P->prox = *L;
	*L = P;

	printf("Item inserido: %d\n", (*L)->Item.Chave);
}

TipoApontador PesquisaLista(TipoLista *L, TipoChave C) {

	TipoApontador P;
	
	P = *L;
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

	// Remove do inicio
	if (P == *L) {
		*L = NULL;
		free(P);
		return SEMERRO;
	}
	
	// Remove no meio ou fim da lista
	TipoApontador aux = *L;
	while(aux->prox != NULL && aux->prox != P) {
		aux = aux->prox;
	}
	
	aux->prox = P->prox;
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
	
	TipoApontador P = *L;

	while(P != NULL) {
		printf("%d ", P->Item.Chave);
		P = P->prox;
	}
	printf("\n");
	
}
